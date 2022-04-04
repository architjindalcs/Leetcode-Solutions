class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[2][amount+1];
              memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++) dp[i%2][0]=1;
  
        for(int i=1;i<=n;i++){
            int coin=coins[i-1];
            for(int amt=1;amt<=amount;amt++){
                if(coin>amt) dp[i%2][amt]=dp[(i-1)%2][amt];
                else{
                    dp[i%2][amt]=dp[(i-1)%2][amt]+dp[i%2][amt-coin];
                }
            }
        }
        return dp[n%2][amount];
    }
};