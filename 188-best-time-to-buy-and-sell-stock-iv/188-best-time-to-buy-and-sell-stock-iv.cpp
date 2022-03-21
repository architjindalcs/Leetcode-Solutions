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
            for(int i=1;i<n;i++){
                int dntst=dp[kval][i-1];
                int maxm=INT_MIN;
                for(int j=i-1;j>=0;j--){
                    maxm=max(maxm,dp[kval-1][j]+(prices[i]-prices[j]));
                }
                dp[kval][i]=max(dp[kval][i-1],maxm);
            }
            
        }
        
        return dp[k][n-1];
        // if(k==0 or prices.size()<=1) return 0;
        // int n=prices.size();
        // int dp[k+1][n];
        // memset(dp,0,sizeof(dp));
        // //case of zero transactions and case of n=0 (single element case), profit will surely be zero
        // for(int kval=1;kval<=k;kval++){
        //     int maxm=-prices[0];
        //     for(int i=1;i<n;i++){
        //         //int maxPro=dp[kval][j-1]; //I dont choose to transact on the current day..
        //         int dontChose=dp[kval][i-1];
        //         int currChose=prices[i]+maxm;
        //         dp[kval][i]=max(currChose,dontChose);
        //         //I keep on updating dp[kval-1][i] - prices[i]
        //         maxm=max(maxm,-prices[i]+dp[kval-1][i]);
        //     }
        // }
        // return dp[k][n-1];
    }
};