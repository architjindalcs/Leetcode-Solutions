class Solution {
public:
    int lcs(string& s1,string& s2){
        int n1=s1.size(),n2=s2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) 
                dp[i][j]=1+dp[i-1][j-1];
                else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
    int minInsertions(string s) {
        /*
            mbadm  -> rev -> mdabm
            
            mam 
        */
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s.size()-lcs(s,s2);
    }
};