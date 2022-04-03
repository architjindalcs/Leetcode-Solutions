class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 and nums[i]>=nums[i+1]) i--;
        if(i==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int swpIdx=i;
        int st=i+1,end=nums.size()-1;
        int idx=-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]>nums[swpIdx]){
                idx=mid;
                st=mid+1;
            }
            else end=mid-1;
        }

        if(idx!=-1){
            swap(nums[swpIdx],nums[idx]);
            reverse(nums.begin()+swpIdx+1,nums.end());
        }
    }
};