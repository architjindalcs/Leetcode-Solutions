class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st=0,end=nums.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            /*
                1,1,2,3,3,4,4,5,5
                0,1,2,3,4,5,6,7,8
            
            */
            int next=(mid==nums.size()-1? INT_MAX: nums[mid+1]);
            int prev=(mid==0? INT_MIN: nums[mid-1]);
            int cnt=(nums[mid]==next)+(nums[mid]==prev);
            if(cnt==0) return nums[mid];
            if(mid&1){
                if(nums[mid-1]==nums[mid]){
                    st=mid+1;
                }
                else end=mid-1;
            }
            else{
                if(nums[mid]==nums[mid+1]){
                    st=mid+1;
                }
                else end=mid-1;
            }
        }
        return -1;
    }
};