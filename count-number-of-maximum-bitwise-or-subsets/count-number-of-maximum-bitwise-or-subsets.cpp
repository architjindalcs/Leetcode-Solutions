class Solution {
public:
    int ans=0;
    void helper(vector<int>& nums,int idx,int oval,int target){
        if(idx==nums.size()){
            if(oval==target) ans++;
            return;
        }
        helper(nums,idx+1,oval,target);
        helper(nums,idx+1,oval|nums[idx],target);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int val=0;
        for(int i: nums) val=val | i;
        helper(nums,0,0,val);
        return ans;
    }
};