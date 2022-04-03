class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int l=1;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
              //  int k=i+l-1;
                /*
                    3,1,5,8
                      i   k
                      1
                */
                //z -> balloon that will burst at last..
                                int k=i+l-1,maxm=0;
                for(int lb=k;lb>=i;lb--){
                    int score=(nums[lb]*(i-1>=0? nums[i-1]:1)*(k+1<=nums.size()-1? nums[k+1]:1));
                    int tscore=score+(lb-1>=i? dp[i][lb-1]: 0)+(lb+1<=k? dp[lb+1][k]: 0);
                    maxm=max(maxm,tscore);
                }
                dp[i][k]=maxm;
            }
                
                // for(int z=k;z>=i;z--){
                //     int leftDP=(i<=z-1? dp[i][z-1]: 0),rightDP=(z+1<=k? dp[z+1][k]: 0);
                //     dp[i][k]=max(dp[i][k],
                //                  leftDP+rightDP+ 
                //                  ((i-1>=0? nums[i-1] : 1)*nums[z]*(k+1<=n-1 ? nums[k+1]: 0 )));
                // }
            // }
        }
        return dp[0][n-1];
        
    }
};