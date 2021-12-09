class Solution {
public:
    int stoneGameVII(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        //dp[i][j] -> difference b/w alice and bob..
        int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=nums[i]+pre[i-1];
        for(int l=2;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                int cf=pre[k]-pre[i]-(dp[i+1][k]);
                int cl=pre[k-1]-(i? pre[i-1]: 0)-(dp[i][k-1]);
                dp[i][k]=max(cf,cl);
            }
        }
        return dp[0][n-1];
    }
};