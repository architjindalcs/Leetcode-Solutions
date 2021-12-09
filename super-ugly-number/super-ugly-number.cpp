class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int p=primes.size();
        int indptr[p];
        memset(indptr,0,sizeof(indptr));
        for(int i=1;i<n;i++){
            int minm=INT_MAX;
            for(int i=0;i<p;i++)
                minm=min(minm,primes[i]*dp[indptr[i]]);
            dp[i]=minm;
            for(int i=0;i<p;i++){
                if(primes[i]*dp[indptr[i]]==minm)
                    indptr[i]++;
            }
        }
        return dp[n-1];
    }
};