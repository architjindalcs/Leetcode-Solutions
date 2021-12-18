class Solution {
public:
    int minScoreTriangulation(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int l=3;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                dp[i][k]=INT_MAX;
                for(int z=i+1;z<=k-1;z++){
                    dp[i][k]=min(dp[i][k],nums[i]*nums[z]*nums[k]+dp[i][z]+dp[z][k]);
                }
            }
        }
        return dp[0][n-1];
    }
};