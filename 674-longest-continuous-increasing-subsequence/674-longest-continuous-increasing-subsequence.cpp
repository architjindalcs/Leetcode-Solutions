class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i=0,ans=1;
        if(nums.size()==1) return 1;
        /*
            1,3,7,4,5,6
              i   i
              
            1,3,5,4,2,3,4,5
                 
        */
        while(i<nums.size()-1){
            if(i<nums.size()-1 and nums[i]>=nums[i+1]){
                i++;
                continue;
            }
            int len=1;
            while(i<nums.size()-1 and nums[i]<nums[i+1]){
                len++;
                i++;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};