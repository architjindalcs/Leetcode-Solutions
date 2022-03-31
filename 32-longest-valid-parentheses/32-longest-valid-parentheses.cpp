class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(!n) return 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                
                if(s[i-1]=='('){
                    dp[i]=max(dp[i],2+(i>=2? dp[i-2]: 0));
                }
                else{
                    // () () )
                    int longestEndingAtPrevIndex=dp[i-1];
                    if(i-longestEndingAtPrevIndex-1>=0 and 
                       s[i-longestEndingAtPrevIndex-1]=='(')
                    dp[i]=max(dp[i],longestEndingAtPrevIndex+2+(i-longestEndingAtPrevIndex-2>=0? dp[i-longestEndingAtPrevIndex-2] : 0));
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
       
    }
};