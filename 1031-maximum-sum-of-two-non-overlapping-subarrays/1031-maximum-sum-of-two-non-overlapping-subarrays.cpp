class Solution {
public:
    int helper(vector<int>& nums,int l1,int l2){
        int sum1=0,sum2=0;
        for(int i=0;i<l1;i++) sum1+=nums[i];
        for(int i=l1;i<l1+l2;i++) sum2+=nums[i];
        int ans=sum1+sum2;
        int lmax=sum1;
        for(int i=l1;i+l2<nums.size();i++){
            sum1+=nums[i];
            sum1-=nums[i-l1];
            sum2+=(nums[i+l2]);
            sum2-=nums[i];
            lmax=max(lmax,sum1);
            ans=max(ans,lmax+sum2);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums,firstLen,secondLen),helper(nums,secondLen,firstLen));
    }
};