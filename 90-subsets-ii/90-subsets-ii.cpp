class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int idx,vector<int>& path){
        ans.push_back(path);

        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(nums,i+1,path);
            path.pop_back();
         //   helper(nums,i+1,path);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        sort(nums.begin(),nums.end());
        
        helper(nums,0,path);
        return ans;
    }
};