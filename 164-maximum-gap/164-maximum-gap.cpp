class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxm=nums[0],minm=nums[0];
        for(int i: nums) {
            maxm=max(maxm,i);
            minm=min(minm,i);
        }
        if(maxm==minm) return 0;
        int n=nums.size();
        int bucketSize=(maxm-minm)%(n-1)==0? (maxm-minm)/(n-1): (maxm-minm)/(n-1)+1;
      //  n=bucketSize;
        vector<int> maxArr(n,INT_MIN);
        vector<int> minArr(n,INT_MAX);

        for(int ele: nums){
            int idx=(ele-minm)/bucketSize;
            maxArr[idx]=max(maxArr[idx],ele);
            minArr[idx]=min(minArr[idx],ele);
        }
       // return -1;
        int prev=INT_MIN;
        int maxGap=INT_MIN;
        for(int i=0;i<n;i++){
            if(maxArr[i]==INT_MIN) continue; 
            if(prev!=INT_MIN){
                maxGap=max(maxGap,minArr[i]-prev);
            }
            prev=maxArr[i];
        }
        return maxGap;
    }
};