class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        //sum(nums)- [minm sum subarray of size nums.size()-k] 
        //sum -> 22 -[4]
        int n=nums.size();
        int pre[n],siz=nums.size()-k;
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++) pre[i]=nums[i]+pre[i-1];
        int sum=pre[n-1];
        if(siz==0) return pre[n-1];
        int minm=INT_MAX;
        for(int i=0;i+siz-1<=n-1;i++){
            int st=i,end=i+siz-1;
            minm=min(minm,pre[end]-(st? pre[st-1]: 0));
        }
        return sum-minm;
    }
};
