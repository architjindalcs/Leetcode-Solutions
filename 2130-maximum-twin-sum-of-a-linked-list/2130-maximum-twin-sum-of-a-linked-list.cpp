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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* getMid(ListNode* head){
        ListNode* s=head;
        ListNode* f=s->next;
        while(f and f->next) {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    int pairSum(ListNode* head) {    
        if(!head) return 0;
        if(!(head->next)) return 0;
        ListNode* mid=getMid(head);
        ListNode* l1=head;
        ListNode* l2=reverse(mid->next);
         mid->next=NULL;
        int ans=0;
        while(l1 and l2){
            ans=max(ans,l1->val+l2->val);
            l1=l1->next;
            l2=l2->next;
        }
        return ans;
    }
};