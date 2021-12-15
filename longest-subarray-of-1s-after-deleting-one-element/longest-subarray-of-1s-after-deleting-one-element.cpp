class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int anas=0,n=nums.size();
        int left[n],cs=0;
        memset(left,0,sizeof(left));
        for(int i=0;i<nums.size();i++){
            if(nums[i]) cs++;
            else cs=0;
            left[i]=cs;
        }

        int ans=left[n-2];
        int next=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans=max(ans,(i>0? left[i-1]: 0)+next);
            if(nums[i]) next++;
            else next=0;
        }
        return ans;
    }
};