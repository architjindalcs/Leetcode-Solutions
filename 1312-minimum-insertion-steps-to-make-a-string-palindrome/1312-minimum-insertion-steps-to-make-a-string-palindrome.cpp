class Solution {
public:
    int lcs(string& s){
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                dp[i][k]=(l==2? (1+(s[i]==s[k])) : (s[i]==s[k]? 2+ dp[i+1][k-1] : max(dp[i+1][k],dp[i][k-1])) );
            }
        }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        /*
            [a]krac[b]cark[a]  -> done..
            [a]ka[b]cr[a]
        */
        
  //      string s2=s;
//        reverse(s2.begin(),s2.end());
        return s.size()-lcs(s);
    }
};