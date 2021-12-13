class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //0<=x<10^10 -> 10^2 -> 0 to  99 -> 2 ditis. no .
        
        int dp[11];
        memset(dp,0,sizeof(dp));
        dp[1]=10;  //0,1,2,3,.....9
        dp[0]=1;  //only 0, 
        
        int mulf=9;
        int prev=9;
        for(int i=2;i<=10;i++){
            dp[i]=(prev*mulf);
            prev=dp[i];
            dp[i]+=dp[i-1];
            mulf--;
        }
        return dp[min(10,n)];
    }
    
};