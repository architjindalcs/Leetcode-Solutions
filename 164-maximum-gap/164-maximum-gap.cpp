class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //https://leetcode.com/problems/maximum-gap/discuss/1241681/JavaPython-Bucket-Idea-with-Picture-Clean-and-Concise-O(N)
        vector<int> minArr(nums.size(),INT_MAX);
        vector<int> maxArr(nums.size(),INT_MIN);
        int minm=INT_MAX,maxm=INT_MIN;
        for(int i: nums) {
            minm=min(minm,i);
            maxm=max(maxm,i);
        }
        if(maxm==minm) return 0;
        int n=nums.size(); 
        int gap=(maxm-minm)%(n-1) ==0 ? (maxm-minm)/(n-1) : ((maxm-minm)/(n-1)) + 1;
        //gap -> minimum value of maximum possible gap in array, means maxium gap >= gap
        
        //say max= 45 min=3 and n=7 -> (42/6) => gap=7  this is the minimum value of maximum possible gap.
        //so assign from [3-9] in bucket 0 and [10-16] in bucket 0 and so on..
        //also, b/w the elements of a bucket, our answer can't be there because there gap is less than minm value of maxgap for sure.
        
        for(int num: nums){
            int bucketIdx=(num-minm)/gap;
            minArr[bucketIdx]=min(minArr[bucketIdx],num);
            maxArr[bucketIdx]=max(maxArr[bucketIdx],num);
        }
        
        int prevMax=INT_MIN, maxGap=INT_MIN;
        for(int i=0;i<n;i++){
            if(minArr[i]==INT_MAX) continue;  //no element falled in this bucket..
            if(prevMax!=INT_MIN) maxGap=max(maxGap,minArr[i]-prevMax);
            prevMax=maxArr[i];
        }
        return maxGap;
    }
};