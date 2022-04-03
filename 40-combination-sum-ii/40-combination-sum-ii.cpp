class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int idx,int cs,int target,vector<int>& path){
        if(target==cs) ans.push_back(path);
        
        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1]) continue;
            if(cs+nums[i]<=target){
                path.push_back(nums[i]);
                helper(nums,i+1,cs+nums[i],target,path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,0,target,path);
        return ans;
    }
};