class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st=0,end=nums.size()-1;
        int ans=0;
        if(target>=nums.back()) return target==nums.back()? nums.size()-1: nums.size();
        if(target<=nums[0]) return 0;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};