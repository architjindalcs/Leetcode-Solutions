class Solution {
public:
    int helper(vector<int>& nums,vector<int>& pre,int stidx,bool left){
        int n=nums.size();
        int st=stidx,end=nums.size()-2;
        int idx=-1;
        int leftSum=pre[stidx-1];
        while(st<=end){
            int mid=(st+(end-st)/2);
            int midSum=(pre[mid]-(pre[stidx-1]));  // [0......stidx-1] [stidx.......mid] [mid+1.......nums.size()-1]
            int rightSum=(pre.back()-midSum-leftSum);
            if(leftSum<=midSum and midSum<=rightSum){
                idx=mid;
                if(left) end=mid-1;
                else st=mid+1;
            }
            else if(leftSum>midSum){
                st=mid+1;
            }
            else end=mid-1;  
        }
        return idx;
    }
    int waysToSplit(vector<int>& nums) {
        long ans=0;
        int mod=1000000007;
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++) pre[i]=nums[i]+pre[i-1];
        for(int i=1;i<nums.size()-1;i++){
            int left=helper(nums,pre,i,true);
            int right=helper(nums,pre,i,false);
            if(left==-1 or right==-1) continue;
            ans=(ans%mod+(right-left+1)%mod)%mod;
        }
        return ans%mod;
    }
};