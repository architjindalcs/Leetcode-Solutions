class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(char ch: s1) cnt[ch-'a']++;
        for(char ch: s2) cnt[ch-'a']++;
        for(char ch: s3) cnt[ch-'a']--;
        for(int i=0;i<26;i++){
            if(cnt[i]) return false;
        }
        
        int n1=s1.size(),n2=s2.size();
        bool dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=true;
        
        for(int i=1;i<=n1;i++){
            dp[i][0]=dp[i-1][0] and (s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n2;i++){
            dp[0][i]=dp[0][i-1] and (s2[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                bool c1=(s1[i-1]==s3[i+j-1] and dp[i-1][j]);
                bool c2=(s2[j-1]==s3[i+j-1] and dp[i][j-1]);
                dp[i][j]=c1 or c2;
            }
        }
        return dp[n1][n2];
        
    }
};