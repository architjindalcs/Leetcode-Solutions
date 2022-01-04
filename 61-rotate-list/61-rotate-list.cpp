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
    int length(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len=length(head);
        if(!head) return NULL;
        k=k%len;
        if(k==0) return head;
        ListNode* nn=new ListNode(0);
        nn->next=head;
        ListNode* prev=nn;
        ListNode* curr=head;
        int cnt=1;
        while(cnt<k){
            curr=curr->next;
            prev=prev->next;
            cnt++;
        }
        ListNode* cp=head;
        ListNode* pp=nn;
        while(curr->next){
            cp=cp->next;
            pp=pp->next;    
            curr=curr->next;
        }        
        ListNode* tail=curr;
        tail->next=head;
        pp->next=NULL;
        return cp;
    }
};