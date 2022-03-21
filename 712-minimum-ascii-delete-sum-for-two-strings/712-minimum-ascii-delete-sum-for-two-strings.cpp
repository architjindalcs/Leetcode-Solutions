class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=(s1[i-1]+dp[i-1][j-1]);
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int sum=0;
        for(char& ch: s1){
            sum+=ch;
        }
        for(char& ch: s2){
            sum+=ch;
        }
        return sum-2*dp[n1][n2];
    }
    
};