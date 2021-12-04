class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(st.size() and nums[st.top()]<=nums[i]) st.pop();
            if(st.size()) nge[i]=st.top();
            else nge[i]=i;
            st.push(i);
        }
        for(int i=0;i<nge.size();i++) nge[i]=nge[i]-i;
        return nge;
    }
};