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
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* helper(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int c=0;
        while(l1 or l2){
            int sum=(l1? l1->val: 0)+(l2? l2->val: 0)+c;
            int app=sum%10;
            c=sum/10;
            ListNode* nn=new ListNode(app);
            if(!head){
                head=tail=nn;
            }
            else{
                tail->next=nn;
                tail=nn;
            }
            l1=(l1? l1->next: l1); l2=(l2? l2->next: l2);
        }
        if(c) {
            ListNode* nn=new ListNode(c);
            if(!head) {
                head=tail=nn;
            }
            else {
                tail->next=nn;
                tail=tail->next;
            }
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverse(helper(reverse(l1),reverse(l2)));
    }
};