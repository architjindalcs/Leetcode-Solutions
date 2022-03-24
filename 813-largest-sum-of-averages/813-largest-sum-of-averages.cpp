class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        k--;
        double dp[n][k+1];
        memset(dp,0,sizeof(dp));
        //size of nums=1 -> only a single number in array.
        //k-1 lines can be drawn, it means..
        dp[0][0]=nums[0]*1.0; //no line can be put
        for(int i=1;i<=k;i++) dp[0][i]=nums[0]*1.0;
        int cs=0;
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            dp[i][0]=(cs/((i+1)*1.0));
        }
       
 
        
        for(int i=1;i<n;i++){
            for(int cuts=1;cuts<=min(k,i);cuts++){
                /*
                    [2,4,3],5
                         i
                */
                double cs=0;
                double maxm=dp[i][cuts-1]; //i am not making a cur
                for(int j=i;j>=0;j--){
                    cs+=nums[j];
                    double val=(j ? dp[j-1][cuts-1]: 0)+ (cs/(1.0*(i-j+1)) );
                    maxm=max(maxm,val);
                }
                //maxm=max(maxm,(cs/(1.0*(i+1))));
               // cout<<"maxm: "<<maxm<<endl;
                dp[i][cuts]=maxm;
            }
        }
        
        return dp[n-1][k];;
    }
};