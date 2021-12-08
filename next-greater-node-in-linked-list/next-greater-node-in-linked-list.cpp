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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int> ans(v.size(),0);
        stack<int> st;
        for(int i=v.size()-1;i>=0;i--){
            while(st.size() and v[st.top()]<=v[i]) st.pop();
            if(st.size())
                ans[i]=v[st.top()];
            st.push(i);
        }
        return ans;
    }
};