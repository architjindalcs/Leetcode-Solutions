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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* nn=new ListNode(0);
        nn->next=list1;
        ListNode* curr=nn;
        int idx=-1;
        ListNode* ptr1=NULL; ListNode* ptr2=NULL;
        while(curr){
            if(idx==(a-1)){
                ptr1=curr;
            }
            if(idx==(b+1)){
                ptr2=curr;
            }
            idx++;
            curr=curr->next;
        }
        ptr1->next=list2;
        ListNode* tmp=list2;
        while(tmp->next) tmp=tmp->next;
        tmp->next=ptr2;
        return nn->next;
    }
};