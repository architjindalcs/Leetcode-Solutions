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
    ListNode* getMid(ListNode* head){
        ListNode* s=head;
        ListNode* f=head->next;
        //1,2,3,4
        //s f
        //
        while(f and f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        if(!(head->next)) return true;
        ListNode* mid=getMid(head);
        ListNode* l1=head;
        ListNode* l2=mid->next;
        mid->next=NULL;
        l2=reverse(l2);
        while(l2){
            if(l1->val!=l2->val) return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
};