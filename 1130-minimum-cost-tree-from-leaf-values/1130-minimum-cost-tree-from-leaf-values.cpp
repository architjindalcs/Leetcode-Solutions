class Solution {
public:
    int mctFromLeafValues(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        int gm[n][n];
        for(int i=0;i<n;i++){
            int maxm=INT_MIN;
            for(int j=i;j<n;j++){
                maxm=max(maxm,nums[j]);
                gm[i][j]=maxm;
            }
        }
        
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=nums[i]*nums[i+1];
        }
        for(int l=3;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                int minm=INT_MAX;
                for(int z=k-1;z>=i;z--){
                    minm=min(minm,dp[z+1][k]+dp[i][z]+gm[i][z]*gm[z+1][k]);            
                }
                dp[i][k]=minm;
            }
        }
        return dp[0][n-1];
    }
};