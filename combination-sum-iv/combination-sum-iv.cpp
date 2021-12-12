class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        uint64_t dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(uint64_t i=1;i<=target;i++){
            for(uint64_t j: nums){
                if(i>=j)
                    dp[i]+=dp[i-j];
            }
        }
        return dp[target];
    }
};