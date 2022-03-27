class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int amt=1;amt<=amount;amt++){
            for(int c: coins){
                if(c>amt) continue;
                if(dp[amt-c]==-1) continue;
                if(dp[amt]==-1) dp[amt]=1+dp[amt-c];
                else dp[amt]=min(dp[amt],1+dp[amt-c]);
            }
        }
        return dp[amount];
    }
};