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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=NULL;
        ListNode* tail=NULL;
        while(head){
            head=head->next;
            int sum=0;
            while(head and head->val){
                sum+=head->val;
                head=head->next;
            } 
            if(!head) continue;
            ListNode* nn=new ListNode(sum);
            if(!ans){
                ans=nn;
                tail=nn;
            }
            else{
                tail->next=nn;
                tail=nn;
            }
        }
        return ans;
    }
};