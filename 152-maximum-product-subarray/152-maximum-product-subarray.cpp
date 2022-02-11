class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxPro=nums[0];
        long long minVal=nums[0],maxVal=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(minVal,maxVal);
            minVal=min((long long)nums[i],(long long)nums[i]*minVal);
            maxVal=max((long long)nums[i],(long long)nums[i]*maxVal);
            maxPro=max(maxPro,maxVal);
        }
        return maxPro;
    }
};