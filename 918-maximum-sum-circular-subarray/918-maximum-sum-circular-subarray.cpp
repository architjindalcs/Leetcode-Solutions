class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int arrSum=0,cs=0,maxm=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cs=max(nums[i],cs+nums[i]);
            arrSum+=nums[i];
            maxm=max(maxm,cs);
            nums[i]=-nums[i];
        }
        cs=0; int maxm2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cs=max(nums[i],cs+nums[i]);
            maxm2=max(maxm2,cs);
        }
        maxm2=-maxm2;
        if(maxm2==arrSum) return maxm;
        return max(maxm,arrSum-maxm2);

    }
};