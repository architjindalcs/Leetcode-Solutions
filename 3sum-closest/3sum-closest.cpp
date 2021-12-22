class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff=INT_MAX,ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=1){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target) return sum;
                int diff=abs(sum-target);
                if(diff<minDiff){
                    minDiff=diff;
                    ans=sum;
                }
                if(sum<target){
                    l++;    
                }
                else r--;
            }
        }
        return ans;
    }
};