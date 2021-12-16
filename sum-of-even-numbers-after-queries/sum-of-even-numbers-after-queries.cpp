class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=(nums[i]%2==0? nums[i]: 0);
        vector<int> ans;
        for(vector<int>& q: queries){
            int val=q[0],idx=q[1];
            sum-=(nums[idx]%2==0? nums[idx]: 0);
            nums[idx]+=val;
            sum+=(nums[idx]%2==0? nums[idx]: 0);
            ans.push_back(sum);
        }
        return ans;
    }
};