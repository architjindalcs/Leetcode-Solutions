class Solution {
public:
    vector<int> pre;
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int idx,int eidx){
        if(idx==nums.size()-1) return 0;
        if(dp[idx][eidx]!=-1) return dp[idx][eidx];
        int ans=0;
        for(int i=idx;i<=eidx-1;i++){
            int sum1=pre[i]-(idx? pre[idx-1]: 0);
            int sum2=pre[eidx]-(pre[i]);
            if(sum1>sum2){
                ans=max(ans,sum2+helper(nums,i+1,eidx));
            }
            else if(sum1<sum2){
                ans=max(ans,sum1+helper(nums,idx,i));
            }
            else ans=max(ans,max(sum2+helper(nums,i+1,eidx),sum1+helper(nums,idx,i)));
        }
        return dp[idx][eidx]=ans;
    }
    int stoneGameV(vector<int>& nums) {
        int n=nums.size();
        dp=vector<vector<int>> (n,vector<int>(n,-1));
        pre=vector<int> (n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=nums[i]+pre[i-1];
        return helper(nums,0,nums.size()-1);
    }
};