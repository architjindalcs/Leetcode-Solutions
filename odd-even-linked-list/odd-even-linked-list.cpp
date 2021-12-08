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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        if(!(head->next)) return head;
        /*
            1->2->3->4->5
               p  c
                     k
               
            1->3->5->2->4
        */
        int idx=1;
        ListNode* curr=head->next;
        ListNode* prev=head;
        
        int cnt=1;
        while(curr){
            if(idx%2==0){
                cnt++;
                //move it in front..
                ListNode* k=curr->next;
                curr->next=head;
                head=curr;
                prev->next=k;
                curr=k;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
            idx++;
        }
        prev=NULL;
        curr=head;
        while(curr and cnt){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            cnt--;
        }
        //1->2->3->4->5  [5->3->1->2->4]
        head->next=curr;
        return prev;
    
    }
};