class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int idx,vector<int>& path,int cs,int target){
        if(cs==target){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i!=idx and nums[i]==nums[i-1]) continue;
            if(cs+nums[i]<=target){
                path.push_back(nums[i]);
                helper(nums,i+1,path,cs+nums[i],target);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,path,0,target);
        return ans;
    }
};