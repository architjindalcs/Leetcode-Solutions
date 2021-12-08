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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[&](ListNode* l1,ListNode* l2){
            return l1->val>l2->val;
        };
        //I am making a minpq..
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        for(ListNode* l: lists) if(l) pq.push(l);
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(pq.size()){
            ListNode* tp=pq.top();
            pq.pop();
            ListNode* nn=new ListNode(tp->val);
            if(!head){
                head=tail=nn;
            }
            else{
                tail->next=nn;
                tail=nn;
            }
            if(tp->next) pq.push(tp->next);
        }
        return head;
    }
};