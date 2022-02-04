class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        string ans="";
        int n=s.size();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            ans=string(1,s[i]);
        }
        int si=0,len=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                if(l==2) dp[i][k]=(s[i]==s[k]);
                else {
                    dp[i][k]=(s[i]==s[k] and dp[i+1][k-1]);
                }
                if(dp[i][k]) {
                    si=i;
                    len=l;
                }
            }
        }
        return s.substr(si,len);
    }
};