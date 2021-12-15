class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(st.size() and nums[st.top()]<nums[i]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
       // return ans;
        for(int i=0;i<nums.size();i++){
          //  if(ans[i]!=-1) continue;
            while(st.size() and nums[st.top()]<nums[i]){
                ans[st.top()]=nums[i];
                st.pop();
            }
        }
        return ans;
    }
};