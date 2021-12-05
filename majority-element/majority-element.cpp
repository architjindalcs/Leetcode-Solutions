class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_idx=0,cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[maj_idx]){
                cnt++;
            }
            else cnt--;
            if(cnt==0){
                maj_idx=i;
                cnt=1;
            }
        }
        return nums[maj_idx];
    }
};