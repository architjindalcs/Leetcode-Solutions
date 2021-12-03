class Solution {
public:
    int numTeams(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=1;i<n-1;i++){
            int lsm=0,lgt=0;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]) lsm++;
                else if(nums[i]<nums[j]) lgt++;
            }
            int rsm=0,rgt=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]) rsm++;
                else if(nums[i]<nums[j]) rgt++;
            }
            ans+=(lsm*rgt)+(lgt*rsm);
        }
        return ans;
    }
};