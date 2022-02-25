/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy= new ListNode(0);
        dummy->next=head;
        ListNode*t=dummy;
        ListNode* temp=t;
        while(temp!=NULL){
            if(temp->next==NULL){
                t->next=NULL;
                return dummy->next;
            }
            else{
                if(temp->next->next==NULL){
                    t->next=temp->next;
                    return dummy->next;     
                }
                else{
                    int n=temp->next->val;
                    if(temp->next->next->val!=n){
                        t->next=temp->next;
                        t=t->next;
                        temp=t;
                    }
                    else{
                        temp=temp->next;
                        while(temp->next && temp->next->val == n){
                            temp=temp->next;
                        }
                    }
                }
            }
        }
        t->next=NULL;
       return dummy->next; 
    }
};