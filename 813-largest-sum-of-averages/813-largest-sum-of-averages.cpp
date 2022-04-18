class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();  //k adj subaarays   [1,|2,3,4|,5] -> k-1 lines..
        k--;
        double dp[k+1][n];
        memset(dp,0.0,sizeof(dp));
        //case of 0 lines..
        double cs=0.0;
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            dp[0][i]=(cs/(1.0*(i+1)));
        }
        
        for(int lines=1;lines<=k;lines++){
            for(int i=lines;i<n;i++){
                double cs=0.0,maxm=0.0;
                for(int z=i;z>=0;z--){
                    cs+=nums[z];
                    /*
                        3,4,5,6,7
                                z
                    */
                    maxm=max(maxm,(z-1>=0? dp[lines-1][z-1]: 0)+(cs/(1.0*(i-z+1))));
                }
                dp[lines][i]=maxm;
            }
        }
        return dp[k][n-1];
    }  
};