/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> nextPtrs;
        Node* ahead=NULL; Node* atail=NULL;
        Node* curr=head;
        while(curr){
            nextPtrs.push_back(curr->next);
            Node* currNext=curr->next;
            Node* nn=new Node(curr->val);
            if(!ahead){
                ahead=nn;
                atail=nn;
            }
            else{
                atail->next=nn;
                atail=atail->next;
            }
            curr->next=nn;
            nn->random=curr;
            curr=currNext;
        }
        curr=head;
        Node* curr2=ahead;
        while(curr2){
            if(curr2->random and curr2->random->random)
            curr2->random=curr2->random->random->next;
            else curr2->random=NULL;
            curr2=curr2->next;
        }
        nextPtrs.push_back(NULL);
        int idx=0;
        while(idx<nextPtrs.size() and curr){
            curr->next=nextPtrs[idx++];
            curr=curr->next;
        }
        return ahead;
        
    }
};