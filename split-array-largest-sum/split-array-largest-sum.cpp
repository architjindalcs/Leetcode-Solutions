class Solution {
public:
    bool poss(vector<int>& nums,int cap,int maxD){
        int days=1,cs=nums[0];
        for(int i=1;i<nums.size();i++){
            cs+=nums[i];
            if(cs>cap){
                cs=nums[i];
                days++;
            }
        }
        return days<=maxD;
    }
    int splitArray(vector<int>& nums, int m) {
        int st=0,end=0;
        for(int i: nums) {
            st=max(st,i);
            end+=i;
        }
        int ans=-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(poss(nums,mid,m)){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};