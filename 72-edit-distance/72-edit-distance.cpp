class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n1;i++) dp[i][0]=i;
        for(int j=0;j<=n2;j++) dp[0][j]=j;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    /*
                        abc -> defg
                          i       j
                        
                        ins -> abc -> def, then add 'c' in it.
                        
                    */
                    
                    int rep=1+dp[i-1][j-1];
                    int ins=1+dp[i][j-1];
                    int rem=1+dp[i-1][j];
                    dp[i][j]=min(rep,min(ins,rem));
                }
            }
        }    
        return dp[n1][n2];
    }
};