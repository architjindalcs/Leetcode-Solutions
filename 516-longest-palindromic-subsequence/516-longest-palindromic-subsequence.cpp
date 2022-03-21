class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                if(l==2) {
                    dp[i][k]=1+(s[i]==s[k]);
                }
                else{
                    if(s[i]==s[k]) dp[i][k]=2+dp[i+1][k-1];
                    else dp[i][k]= max(dp[i+1][k],dp[i][k-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};