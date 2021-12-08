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
    ListNode* helper(ListNode* head,int gsiz){
        if(!head) return NULL;
        int cnt=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp and cnt<gsiz){
            if(!prev){
                prev=temp;
            }
            else prev=prev->next;
            cnt++;
            temp=temp->next;
        }

        if(cnt%2){
            prev->next=helper(temp,gsiz+1);
            return head;
        }
        else{
            //I needto reverse..
            int cnt=0;
            ListNode* curr=head;
            ListNode* prev=NULL;
            while(curr and cnt<gsiz){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                cnt++;
            }
            head->next=helper(curr,gsiz+1);
            return prev;
        }
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return helper(head,1);
    }
};