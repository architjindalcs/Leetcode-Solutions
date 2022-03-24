class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        uint64_t dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int t=1;t<=target;t++){
            for(int& ele: nums){
                if(t>=ele) dp[t]+=dp[t-ele];
            }
        }
        return dp[target];
    }
};