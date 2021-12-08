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
    ListNode* middleNode(ListNode* head) {
        ListNode* s=head;
        ListNode* f=s;
        /*
            1->2->3->4
            s  s  s
            f     f    f
            s  f
            
            1->2->3->4->5
               s  s   f 
        */
        while(f and f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
};