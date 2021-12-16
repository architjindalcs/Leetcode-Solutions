class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]!='0') dp[i]=dp[i-1];  //taking the prev ways and considering it as
            //an added character to the previous breakups..
            if(s[i-1]!='0'){
                int ltwo=(10*(s[i-1]-'0')+(s[i]-'0'));
                if(ltwo>=10 and ltwo<=26){
                    dp[i]+=(i-2>=0? dp[i-2]: 1);
                }
            }
        }
        return dp[n-1];
    }
};