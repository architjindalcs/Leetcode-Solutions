class Solution {
public:
    int helper(vector<int>& nums,int l1,int l2){
        int maxm=INT_MIN;
        int sum1=0,sum2=0;
        for(int i=0;i<l1;i++) sum1+=nums[i];
        for(int i=0;i<l2;i++) sum2+=nums[i+l1];
        int lmax=sum1;
        maxm=sum1+sum2;
        for(int i=l1;i+l2<nums.size();i++){
            sum1=sum1-nums[i-l1]+nums[i];
            lmax=max(lmax,sum1);
            sum2=sum2-nums[i]+nums[i+l2];
            maxm=max(maxm,lmax+sum2);
        }
        return maxm;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums,firstLen,secondLen),helper(nums,secondLen,firstLen));
    }
};