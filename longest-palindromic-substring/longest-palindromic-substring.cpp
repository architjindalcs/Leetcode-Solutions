class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        int si=0,len=1;
        memset(dp,0,sizeof(dp));
        int ans=1;
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                if(l==2) {
                    dp[i][i+1]=(s[i]==s[i+1]);
                    if(dp[i][i+1])
                    {si=i,len=2;}
                    continue;
                }
                int k=i+l-1;
                dp[i][k]=(s[i]==s[k] and dp[i+1][k-1]);
                if(dp[i][k]){
                    si=i,len=l;
                }
            }
        }
        return s.substr(si,len);
    }
};