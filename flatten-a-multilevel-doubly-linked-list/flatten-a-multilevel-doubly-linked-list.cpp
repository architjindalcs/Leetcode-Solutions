/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* ans=NULL;
    void helper(Node* head,Node*& tail){
        if(!head) return;
        if(!ans){
            ans=head;
            tail=head;
        }
        else{
            tail->next=head;
            head->prev=tail;
            tail=head;
        }
        Node* next=head->next;
        if(head->child){
            helper(head->child,tail);
            head->child=NULL;
        }
        helper(next,tail);  
    }
    Node* flatten(Node* head) {
        Node* prev=NULL;
        helper(head,prev);
        return head;
    }
};