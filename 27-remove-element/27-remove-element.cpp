class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int st=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                swap(nums[++st],nums[i]);
            }
        }
        return st+1;
    }
};