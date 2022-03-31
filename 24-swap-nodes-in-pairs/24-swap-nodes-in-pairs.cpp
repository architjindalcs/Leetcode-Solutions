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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !(head->next)) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* ans=NULL;
        while(curr and curr->next){
            ListNode* temp=curr->next;
            curr->next=temp->next;
            temp->next=curr;
            if(!ans){
                ans=temp;
            }
            else{
                prev->next=temp;
            }
            prev=curr;
            curr=curr->next;
        }
        return ans;
    }
};