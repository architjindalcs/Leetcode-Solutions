class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minVal=nums[0],maxVal=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(minVal,maxVal);
            //1,10  -5 ,minVal=10,maxVal=1;
            minVal=min(minVal*nums[i],nums[i]); //new subarray may also be started..
            maxVal=max(maxVal*nums[i],nums[i]);
            ans=max(ans,maxVal);
        }
        return ans;
    }
};