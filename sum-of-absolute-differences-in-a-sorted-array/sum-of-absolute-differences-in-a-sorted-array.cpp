class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]=nums[i]+pre[i-1];
        for(int i=0;i<nums.size();i++)
            ans[i]=(i+1)*nums[i]-(n-i-1)*nums[i]-(pre[i])+(pre[n-1]-pre[i]);
        return ans;
    }
};