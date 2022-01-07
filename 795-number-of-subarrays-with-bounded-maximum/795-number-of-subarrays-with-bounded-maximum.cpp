class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0,cnt=0;
        int i=0,j=0;
        while(i<nums.size()){
            if(nums[i]>=left and nums[i]<=right){
                cnt=(i-j+1);
                ans+=cnt;  //saare ke saare subarrays range me honge..
            }
            else if(nums[i]<left){
                ans+=(cnt);
            }
            else{
                cnt=0;    
                j=i+1;  
            }
            i++;
        }
        return ans;
    }
};