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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head) return {-1,-1};
        if(!(head->next)) return {-1,-1};
        if(!(head->next->next)) return {-1,-1};
        int first=-1,last=-1;
        int pidx=-1;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int idx=1;
        int minDist=INT_MAX;
        while(curr and curr->next){
            int pval=prev->val;
            int cval=curr->val;
            int nval=curr->next->val;
            if((cval>pval and cval>nval) or (cval<pval and cval<nval)){
                if(pidx!=-1)
                minDist=min(minDist,idx-pidx);
                if(first==-1) first=idx;
                else last=idx;
                pidx=idx;
            }
            prev=prev->next;
            curr=curr->next;
            idx++;
        }
        int maxDist=last-first;
        if(minDist!=INT_MAX) return {minDist,maxDist};
        return {-1,-1};
    }
};