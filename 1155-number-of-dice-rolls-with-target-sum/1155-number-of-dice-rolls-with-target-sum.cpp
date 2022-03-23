class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod=1000000007;
        long dp[n+1][target+1];
        memset(dp,0,sizeof(dp));

        dp[0][0]=1; //0 is the no of dice and 0 is the target to be acheived..
        
        
        for(int cnt=1;cnt<=n;cnt++){
            for(int t=1;t<=target;t++){
                for(int fval=1;fval<=min(k,t);fval++){
                    dp[cnt][t]=(dp[cnt][t]%mod+dp[cnt-1][t-fval]%mod)%mod;
                }
            }
        }
        return dp[n][target]%mod;
    }
};