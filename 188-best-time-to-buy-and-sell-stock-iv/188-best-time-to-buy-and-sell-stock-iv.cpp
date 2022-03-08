class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 or prices.size()<=1) return 0;
        int n=prices.size();
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        //case of zero transactions and case of n=0 (single element case), profit will surely be zero
        for(int kval=1;kval<=k;kval++){
            int maxm=-prices[0];
            for(int i=1;i<n;i++){
                //int maxPro=dp[kval][j-1]; //I dont choose to transact on the current day..
                int dontChose=dp[kval][i-1];
                int currChose=prices[i]+maxm;
                dp[kval][i]=max(currChose,dontChose);
                maxm=max(maxm,-prices[i]+dp[kval-1][i]);
            }
        }
        return dp[k][n-1];
    }
};