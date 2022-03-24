class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[1]=0;
        
        for(int i=2;i<=n;i++){
            dp[i]=i;
            for(int j=1;j<=i/2;j++){
                if(i%j==0){
                    /*
                        [AA]AAAA
                         DP[2] + (6/2) = 3
                    */
                    dp[i]=min(dp[i],dp[j]+(i/j));
                }
            }
        }
        return dp[n];
    }
};