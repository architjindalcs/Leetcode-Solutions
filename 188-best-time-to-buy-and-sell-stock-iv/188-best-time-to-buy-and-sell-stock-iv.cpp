class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 or prices.size()<=1) return 0;
        int n=prices.size();
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        //case of zero transactions and case of n=0 (single element case), profit will surely be zero
        for(int kval=1;kval<=k;kval++){
            for(int j=1;j<n;j++){
                int maxPro=dp[kval][j-1];
                for(int z=j-1;z>=0;z--){
                    maxPro=max(maxPro,prices[j]-prices[z]+dp[kval-1][z]);
                }
                dp[kval][j]=maxPro;
            }
        }
        return dp[k][n-1];
    }
};