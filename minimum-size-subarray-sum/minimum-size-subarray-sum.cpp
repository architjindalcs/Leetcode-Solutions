class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX,i=0,st=0,cs=0;
        while(i<nums.size()){
            cs+=nums[i];
            while(st<i and cs-nums[st]>=target){
                cs-=nums[st];
                st++;
            }
            if(cs>=target) minLen=min(minLen,i-st+1);
            i++;
        }
        return minLen==INT_MAX? 0: minLen;
    }
};