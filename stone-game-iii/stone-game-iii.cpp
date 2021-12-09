class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            int c1=nums[i]-(i<n-1? dp[i+1]:0);
            int c2=nums[i]+(i+1<=n-1? nums[i+1]: 0)-(i<n-2? dp[i+2]: 0);
            int c3=nums[i]+(i+1<=n-1? nums[i+1]: 0)+(i+2<=n-1? nums[i+2]: 0)
                -(i<n-3? dp[i+3]:0);
            dp[i]=max(c1,max(c2,c3));
        }
        return dp[0]==0? "Tie": (dp[0]>0? "Alice": "Bob");
    }
};