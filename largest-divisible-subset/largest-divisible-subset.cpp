class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        vector<int> parent(n,-1);
        int maxLen=1,idx=0;
        //longest increasing subsequence kind of thing..
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 and 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    parent[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                idx=i;
            }
        }
        vector<int> ans;
        while(true){
            ans.push_back(nums[idx]);
            idx=parent[idx];
            if(idx==-1) return ans;
        }
        return ans;
    }
};