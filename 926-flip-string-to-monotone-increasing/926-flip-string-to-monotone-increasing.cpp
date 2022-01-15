class Solution {
public:
    int minFlipsMonoIncr(string s) {
      //aaaaaaaabbb   aaaaaaaaaaaaaaab   b
        int n=s.size();
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        int ocnt=(s[0]=='1');
        dp[0][0]=(s[0]=='1');
        dp[0][1]=(s[0]=='0');
        for(int i=1;i<s.size();i++){
            //dp[i][0] -> ending with 0 only..
            if(s[i]=='1') ocnt++;
            if(s[i]=='0'){
                dp[i][0]=dp[i-1][0];  //yeh bhi zero h, just take prev value..
                dp[i][1]=1+min(dp[i-1][0],dp[i-1][1]);
            }
            else{
                //current is '1';
                dp[i][0]=min(ocnt,1+dp[i-1][0]);
                dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};