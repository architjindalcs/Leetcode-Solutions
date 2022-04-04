class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i: nums) sum+=i;
        if(sum&1) return false;
        int rs=sum/2;
        bool dp[rs+1];
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int ele: nums){
            for(int i=rs;i>=ele;i--) if(dp[i-ele]) dp[i]=dp[i-ele];
        }
        return dp[rs];
    }
};