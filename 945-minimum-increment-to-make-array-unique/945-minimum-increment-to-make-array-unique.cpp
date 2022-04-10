class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        //1,1,2,2,3,7 -> 
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                ans+=(abs(nums[i]-nums[i-1]))+1;
                nums[i]+=(abs(nums[i]-nums[i-1]))+1;
            }
        }
        return ans;
    }
};