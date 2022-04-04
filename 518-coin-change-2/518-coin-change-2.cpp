class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
              memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++) dp[i][0]=1;
  
        for(int i=1;i<=n;i++){
            int coin=coins[i-1];
            for(int amt=1;amt<=amount;amt++){
                if(coin>amt) dp[i][amt]=dp[i-1][amt];
                else{
                    dp[i][amt]=dp[i-1][amt]+dp[i][amt-coin];
                }
            }
        }
        return dp[n][amount];
    }
};