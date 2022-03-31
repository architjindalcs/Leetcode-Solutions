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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=1;
        ListNode* nn=new ListNode(0);
        nn->next=head;
        ListNode* temp=head;
      //  int cnt=1;
        while(cnt<n){
            temp=temp->next;
            cnt++;
        }
        ListNode* curr=head;
        ListNode* prev=nn;
        while(temp->next){
            curr=curr->next;
            prev=prev->next;
            temp=temp->next;
        }
        prev->next=curr->next;
        return nn->next;
    }
};