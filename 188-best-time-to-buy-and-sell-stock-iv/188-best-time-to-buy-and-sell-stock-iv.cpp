class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 or prices.size()<=1) return 0;
        int n=prices.size();
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        
        for(int kval=1;kval<=k;kval++){
            //kval-> no of transactions we can do
            dp[kval][0]=0;  //no profit possible...
            int maxm=dp[kval-1][0]-prices[0]; //-prices[0] effectively..
            for(int i=1;i<n;i++){
                int dntst=dp[kval][i-1];
                int tst=prices[i]+maxm;
                dp[kval][i]=max(dntst,tst);
                maxm=max(maxm,dp[kval-1][i]-prices[i]);
            }
        }
        
        return dp[k][n-1];
    }
};