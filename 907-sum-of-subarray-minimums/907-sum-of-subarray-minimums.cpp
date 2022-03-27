class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> nse(n),pse(n);
        for(int i=0;i<=nums.size();i++){
            while(st.size() and (i==n or nums[st.top()]>=nums[i])){
                int tpidx=st.top();
                st.pop();
                int nextSmallerIdx=i;
                int prevSmallerIdx=-1;
                if(st.size())
                    prevSmallerIdx=st.top();
                nse[tpidx]=nextSmallerIdx;
                pse[tpidx]=prevSmallerIdx;
            }
            st.push(i);
        }
        long ans=0;
        int mod=1000000007;
        for(int i=0;i<nums.size();i++){
            long left=((long)i-pse[i]);
            long right=((long)nse[i]-i);
            ans=(ans%mod+(left%mod*right%mod*nums[i]%mod)%mod)%mod;
        }
        return ans%mod;
        
       // return -1;
    }
};