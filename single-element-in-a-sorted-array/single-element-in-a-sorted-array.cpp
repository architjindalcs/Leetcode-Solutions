class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st=0,end=nums.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            int next=(mid==nums.size()-1? INT_MAX: nums[mid+1]);
            int prev=(mid==0? INT_MIN: nums[mid-1]);
            int cnt=(nums[mid]==next)+(nums[mid]==prev);
            if(cnt==0) return nums[mid];
            
            if(mid%2==0){
                //next element must be same..
                if(mid+1<nums.size() and nums[mid]==nums[mid+1]){
                    st=mid+1; //iska mtlb insertion jo h, vo left me nhi 
                }
                else {
                    end=mid-1;
                }
            }
            else{
                if(mid-1>=0 and nums[mid]==nums[mid-1]){
                    st=mid+1;
                }
                else end=mid-1;
            }
        }
        return -1;
    }
};