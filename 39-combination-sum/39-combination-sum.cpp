class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums,int idx,int cs,int target,vector<int>& path){
        if(target==cs) ans.push_back(path);
        if(idx==nums.size()){
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            if(cs+nums[i]<=target){
                path.push_back(nums[i]);
                helper(nums,i,cs+nums[i],target,path);
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