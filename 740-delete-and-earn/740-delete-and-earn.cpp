class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxm=*max_element(nums.begin(),nums.end());
        int dp[maxm+1];
        memset(dp,0,sizeof(dp));
        
        for(int num: nums) dp[num]+=num;
        
        int prev_exc=0,prev_inc=dp[0];
        for(int i=1;i<=maxm;i++){
            int curr_inc=dp[i]+prev_exc;
            int curr_exc=max(prev_inc,prev_exc);
            prev_exc=curr_exc;
            prev_inc=curr_inc;
        }
        
        return max(prev_inc,prev_exc);
    }
};