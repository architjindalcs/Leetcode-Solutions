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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* nn=new ListNode(0);
        nn->next=head;
        ListNode* curr=head;
        ListNode* prev=nn;
        int idx=1;
        while(curr){
            if(idx==left){
                //i have reached..
                ListNode* coo=curr;
                ListNode* pptr=prev;
                int cnt=right-left+1;
                while(cnt--){
                    ListNode* temp=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=temp;
                }
                
                pptr->next=prev;
                coo->next=curr;
                return nn->next;
                
            }
            else{
                curr=curr->next;
                prev=prev->next;
                idx++;
            }
        }
        return nn->next;
    }
};