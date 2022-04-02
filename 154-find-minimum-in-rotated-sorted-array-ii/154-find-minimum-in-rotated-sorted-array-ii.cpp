class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0,end=nums.size()-1;
        int minm=INT_MAX;
        while(st<=end){
            int ele1=nums[st];
            while(st<=end and nums[st]==ele1) st++;
            st--;
            int ele2=nums[end];
            while(st<=end and nums[end]==ele2) end--;
            end++;
            int mid=(st+end)/2;
            minm=min(minm,nums[mid]);
            
            if(nums[mid]>=nums[end]) {
                //left half is sorted..
                minm=min(minm,nums[st]);
                st=mid+1;
            }
            else end=mid-1;
        }
        return minm;
    }
};