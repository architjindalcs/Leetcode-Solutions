class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=0;
        dp[2]=min(cost[0],cost[1]);  //2 elements are there in array, for reach 2nd index..
        //i can take min(cost[0],cost[1]) 
        
        for(int i=3;i<=n;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};