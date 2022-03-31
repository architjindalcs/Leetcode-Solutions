class Solution {
public:
    bool mymatch(string s,string p){
        int n1=s.size(),n2=p.size();
        bool dp[n1+1][n2+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;  
        //empty string can match with.. a*b*c* kind of pattern, here, it can eventually lead to empty string..
        
        for(int j=2;j<=n2;j++){
            if(p[j-1]=='*' and dp[0][j-2]) dp[0][j]=true;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==p[j-1] or p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] =  dp[i][j-2];  //considering zero matches wala case..
                     
                    if(s[i-1]==p[j-2] or p[j-2]=='.'){
                        dp[i][j]=dp[i][j] or dp[i-1][j];
                    }   
                }
                else dp[i][j]=false;
            }
        }
        return dp[n1][n2];
    }
    bool isMatch(string s, string p) {
        return mymatch(s,p);
      //  return false;
    }
};