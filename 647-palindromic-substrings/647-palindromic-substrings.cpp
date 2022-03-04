class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int ans=n;
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                dp[i][k]=(l==2? (s[i]==s[k]): (s[i]==s[k] and dp[i+1][k-1]));
                ans+=dp[i][k];
            }
        }
        return ans;
    }
};