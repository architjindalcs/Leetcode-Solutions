class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=4;i++) dp[1][i]=i+1;
        
        for(int len=2;len<=n;len++){
            
            int sum=0;
            for(int end=0;end<=4;end++){
                sum+=(dp[len-1][end]);
                dp[len][end]=sum;
            }
        }
        return dp[n][4];
    }
};