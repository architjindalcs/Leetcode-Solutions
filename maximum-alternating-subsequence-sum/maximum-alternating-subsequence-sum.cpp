class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=nums[0]; dp[0][1]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],nums[i]+dp[i-1][1]);
            dp[i][1]=max(dp[i-1][1],-nums[i]+dp[i-1][0]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};