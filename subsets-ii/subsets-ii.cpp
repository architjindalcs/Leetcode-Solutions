class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,vector<int>& temp,int idx){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(nums,temp,0);
        return ans;
    }
};