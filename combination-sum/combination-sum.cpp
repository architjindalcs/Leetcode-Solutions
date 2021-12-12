class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int cs,int idx,int target,vector<int>& path){
        if(cs==target){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(cs+nums[i]<=target){
                path.push_back(nums[i]);
                helper(nums,cs+nums[i],i,target,path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        helper(candidates,0,0,target,path);
        return ans;
    }
};