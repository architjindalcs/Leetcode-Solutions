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
    ListNode* reverse(ListNode* head,int k){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(cnt<k) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        cnt=0;
        while(cnt<k){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            cnt++;
        }
        head->next=reverse(curr,k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);
    }
};