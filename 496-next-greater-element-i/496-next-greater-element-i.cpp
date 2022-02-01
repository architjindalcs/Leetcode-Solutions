class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() and nums2[st.top()]<=nums2[i])
                st.pop();
            if(st.size())
                mp[nums2[i]]=nums2[st.top()];
            st.push(i);
        }
        vector<int> ans;
        for(int i: nums1){
            if(mp.count(i)) ans.push_back(mp[i]);
            else ans.push_back(-1);
        }
        return ans;
    }
};