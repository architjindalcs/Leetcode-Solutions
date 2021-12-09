class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[1]=1;
        int i2,i3,i5;
        i2=i3=i5=1;
        for(int i=2;i<=n;i++){
            int minm=min(2*dp[i2],min(3*dp[i3],5*dp[i5]));
            dp[i]=minm;
            if(minm==2*dp[i2]) i2++;
            if(minm==3*dp[i3]) i3++;
            if(minm==5*dp[i5]) i5++;
        }
        return dp[n];
    }
};