class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        //dp[i][0] -> not having the stock on the ith day..
        dp[0][0]=0; dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],prices[i]+dp[i-1][1]);
            dp[i][1]=max(dp[i-1][1],-prices[i]+(i>=2? dp[i-2][0]: 0));
        }
        return dp[n-1][0];
    }
};