class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=4;i++) dp[1][i]=1;  //dp[i][j] = number of strings of length i ending at vowel j..
        
        for(int len=2;len<=n;len++){
            
            int sum=0;
            for(int end=0;end<=4;end++){
                sum+=(dp[len-1][end]);  //for eg: end=3, it should also include ending at 0,1,2,3 all, so taking sum for cumulative addition
                dp[len][end]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<=4;i++) ans+=dp[n][i];
        return ans;
    }
};