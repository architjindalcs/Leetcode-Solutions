/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        ListNode* meet=NULL;
        while(f and f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) {
                meet=s;
                break;
            }
        }
        if(!meet) return NULL; //koi cycle nhi h linked list me..
        ListNode* st=head;
        while(st!=meet){
            st=st->next;
            meet=meet->next;
        }
        return st;
    
    }
};