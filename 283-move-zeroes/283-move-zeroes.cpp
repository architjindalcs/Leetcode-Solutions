class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) swap(nums[++st],nums[i]);
        }
        
    }
};