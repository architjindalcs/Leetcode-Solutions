class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        if(k==0) return 0;
        int dp[n][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++){
            for(int kval=1;kval<=k;kval++){
                int maxm=dp[i-1][kval];  //not transacting on the ith day...so kval remains same
                for(int j=i-1;j>=0;j--){
                    maxm=max(maxm,prices[i]-prices[j]+dp[j][kval-1]);
                }
                dp[i][kval]=maxm;
            }
        }
        return dp[n-1][k];
    }
};