class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int st=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                swap(nums[++st],nums[i]);
            }
        }
        return nums;
    }
};