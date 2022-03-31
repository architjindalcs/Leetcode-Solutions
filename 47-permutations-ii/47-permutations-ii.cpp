class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=idx;i<nums.size();i++){
            if(!st.count(nums[i])){
                swap(nums[i],nums[idx]);
                st.insert(nums[idx]);
                helper(nums,idx+1);
                swap(nums[i],nums[idx]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
        helper(nums,0);
        return ans;
    }
};