class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int idx,vector<int>& path){
        ans.push_back(path);
        
        for(int i=idx;i<nums.size();i++){
            path.push_back(nums[i]);
            helper(nums,i+1,path);
            path.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        helper(nums,0,path);
        return ans;
    }
};