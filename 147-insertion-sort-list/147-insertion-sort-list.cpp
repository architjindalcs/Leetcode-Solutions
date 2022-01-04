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
        if(!head) return head;
        ListNode* s=head;
        ListNode* f=head->next;
        while(f and f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<l2->val){
            ListNode* nn=new ListNode(l1->val);
            nn->next=merge(l1->next,l2);
            return nn;
        }
        ListNode* nn=new ListNode(l2->val);
        nn->next=merge(l1,l2->next);
        return nn;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        if(!(head->next)) return head;
        ListNode* mid=getMid(head);
        ListNode* l2=mid->next;
        mid->next=NULL;
        ListNode* l1=head;
        return merge(insertionSortList(l1),insertionSortList(l2));
    }
};