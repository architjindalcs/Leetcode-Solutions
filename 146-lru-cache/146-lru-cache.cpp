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
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> keyAddr;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void insertNode(Node* node){
        //insert a node just after the head..least recently used node..
        Node* headNext=head->next;
        head->next=node;
        node->prev=head;
        node->next=headNext;
        headNext->prev=node;
    }
    void removeNode(Node* node){
        Node* nodeNext=node->next;
        Node* nodePrev=node->prev;
        nodePrev->next=nodeNext;
        nodeNext->prev=nodePrev;
    }
    int get(int key) {
        if(!keyAddr.count(key)) return -1;
        int val=keyAddr[key]->val;
        removeNode(keyAddr[key]);
        insertNode(keyAddr[key]);  //now this is most recently used..
        return val;
    }
    
    void put(int key, int value) {
        if(keyAddr.count(key)){
            //it was already present, good
            keyAddr[key]->val=value;
            removeNode(keyAddr[key]);
            insertNode(keyAddr[key]);
            return;
        }
        if(keyAddr.size()==cap){
            keyAddr.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        Node* nn=new Node(key,value);
        keyAddr[key]=nn;
        insertNode(nn);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */