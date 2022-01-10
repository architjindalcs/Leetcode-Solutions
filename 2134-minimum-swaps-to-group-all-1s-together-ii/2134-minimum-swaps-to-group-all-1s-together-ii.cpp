class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cntOnes=0;
        for(int i: nums) cntOnes+=(i==1);
        if(!cntOnes) return 0;
        int winSize=cntOnes;
        int ans=INT_MAX;
        int cones=0;
        vector<int> pre;
        int psum=0;
        for(int i: nums) {
            psum+=i;
            pre.push_back(psum);
        }
        for(int i=0;i<winSize;i++){
            cones+=(nums[i]);
        }
        ans=min(ans,winSize-cones);
        for(int i=winSize;i<nums.size();i++){
            cones+=(nums[i]);
            cones-=(nums[i-winSize]);
            ans=min(ans,winSize-cones);
        }
        int pidx=1;
        while(pidx<cntOnes){
            int suff=cntOnes-pidx;
            int aageSum=(pre[pidx-1]);
            int end=nums.size()-1;
            int st=end-suff+1;
            int peecheSum=(pre.back()-(st? pre[st-1]: 0));
            ans=min(ans,winSize-(aageSum+peecheSum));
            pidx++;
        }
        return ans;
    }
};