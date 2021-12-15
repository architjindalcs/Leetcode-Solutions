class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx1=-1,idx2=-1;
        int minm=INT_MAX,maxm=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxm){
                maxm=nums[i];
                idx1=i;
            }
            if(nums[i]<minm){
                minm=nums[i];
                idx2=i;
            }
        }
        int n=nums.size();
        if(idx1<idx2){
            int v1=n-idx2+idx2-idx1;
            int v2=idx1+1+idx2-idx1;
            int v3=n-idx2+(idx1+1);
            return min(v1,min(v2,v3));
        }
        int v1=n-idx1+idx1-idx2;
        int v2=idx2+1+idx1-idx2;
        int v3=n-idx1+(idx2+1);
        return min(v1,min(v2,v3));
    }
};