// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way
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

class LRUCache
{
    private:

    public:
      int cap;
    Node* head;
    Node* tail;
        unordered_map<int,Node*> keyAddr;

    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
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
    //Function to return value corresponding to the key.
    int get(int key)
    {
                if(!keyAddr.count(key)) return -1;
        int val=keyAddr[key]->val;
        removeNode(keyAddr[key]);
        insertNode(keyAddr[key]);  //now this is most recently used..
        return val;
        // your code here
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
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
        // your code here   
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends