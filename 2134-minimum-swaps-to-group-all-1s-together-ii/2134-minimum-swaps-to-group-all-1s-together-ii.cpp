class Solution {
public:
    int helper(vector<int>& nums){
        int cntOnes=0;
        for(int i: nums) cntOnes+=(i==1);
        if(!cntOnes) return 0;
        int winSize=cntOnes/2;
        int ans=INT_MAX;
        int cones=0;

        for(int i=0;i<winSize;i++){
            cones+=(nums[i]);
        }
        ans=min(ans,winSize-cones);
        for(int i=winSize;i<nums.size();i++){
            cones+=(nums[i]);
            cones-=(nums[i-winSize]);
            ans=min(ans,winSize-cones);
        }
        return ans; 
    }
    int minSwaps(vector<int>& nums) {
        vector<int> temp=nums;
        for(int i: nums) temp.push_back(i);
        return helper(temp);
    }   
};