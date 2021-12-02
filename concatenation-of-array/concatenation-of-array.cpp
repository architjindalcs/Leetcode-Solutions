class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int siz=nums.size();
        for(int i=0;i<siz;i++) nums.push_back(nums[i]);
        return nums;
    }
};