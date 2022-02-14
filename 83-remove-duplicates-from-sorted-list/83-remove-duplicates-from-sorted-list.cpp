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
        ListNode* curr=head;
        while(curr){
            if(curr->next and curr->next->val!=curr->val){
                curr=curr->next;
                continue;
            }
            int val=curr->val;
            ListNode* prev=curr;
            while(curr and curr->val==val) curr=curr->next;
            prev->next=curr;
        }
        return head;
    }
};