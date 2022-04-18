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
    Node* tail=NULL;
    Node* ans=NULL;
    void helper(Node* head){
        if(!head) return;
        Node* headNext=head->next;
        if(!tail){
            ans=head;
            tail=head;
        }
        else{
            tail->next=head;
            head->prev=tail;
            tail=head;
        }
        if(head->child) {
            helper(head->child);
            head->child=NULL;
        }
        helper(headNext);
    }
    Node* flatten(Node* head) {
        helper(head);
        return ans;
    }
};