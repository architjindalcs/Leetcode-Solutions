class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0; //no coin is needed to make an zero amount..
        
        for(int i=1;i<=amount;i++){
            for(int c: coins){
                if(c<=i){
                    if(dp[i-c]!=-1)
                        dp[i]=(dp[i]==-1? 1+dp[i-c]: min(dp[i],1+dp[i-c]));
                }         
            }
        }
        return dp[amount];
    }
};