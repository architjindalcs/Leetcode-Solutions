class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        prev=next=NULL;
    }
};
class LRUCache {
public:
    //keep the most recently used as the head's next..
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> keyAddr;   //maintains key and correspoding address
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail; tail->prev=head;
        cap=capacity;
    }
    void insertNode(Node* node){
        //it would insert a node..just after head..
        Node* headNext=head->next;
        node->next=headNext;
        headNext->prev=node;
        head->next=node;
        node->prev=head;
    }
    void deleteNode(Node* node){
        //it would delete a node..
        Node* myPrev=node->prev;
        Node* myNext=node->next;
        myPrev->next=myNext;
        myNext->prev=myPrev;  //ayy, i am gone now..
    }
    int get(int key) {
        if(keyAddr.count(key)){
            int val=keyAddr[key]->val;
            Node* keyNode=keyAddr[key];
            deleteNode(keyNode);  //deleting the node..
            insertNode(keyNode);  //making it head's next  (Most recently used..);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyAddr.count(key)){
            keyAddr[key]->val=value;  //updated the value..
            deleteNode(keyAddr[key]);
            insertNode(keyAddr[key]);
            return;
        }
        if(keyAddr.size()==cap){
            //now, we need to evict..
            keyAddr.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* nn=new Node(key,value);
        insertNode(nn);
        keyAddr[key]=nn;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */