class Node{
    public:
    int key,value;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        next=prev=NULL;
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
    void insert(Node* node){
        //insert a node just after head.
        Node* headNext=head->next;
        head->next=node;
        node->prev=head;
        node->next=headNext;
        headNext->prev=node;
    }
    void remove(Node* node){
        Node* pptr=node->prev;
        Node* nptr=node->next;
        pptr->next=nptr;
        nptr->prev=pptr;
    }
    int get(int key) {
        if(!keyAddr.count(key)) return -1;
        Node* addr=keyAddr[key];
        remove(addr);
        insert(addr);
        return addr->value;
    }
    
    
    void put(int key, int value) {
        if(keyAddr.count(key)){
            keyAddr[key]->value=value;
            remove(keyAddr[key]);
            insert(keyAddr[key]);
            return;
        }    
        if(keyAddr.size()==cap){
            keyAddr.erase(tail->prev->key);
            remove(tail->prev);
        }
        Node* nn=new Node(key,value);
        keyAddr[key]=nn;
        insert(nn);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */