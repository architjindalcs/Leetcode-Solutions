class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<int> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int>> > minHeap;
        int minv,maxv,minDiff=INT_MAX;
        for(int i=0;i<nums.size();i++){
            minHeap.push({nums[i][0],i});
            maxHeap.push(nums[i][0]);
        }
        vector<int> nI(nums.size(),1);
        while(minHeap.size()){
            int minVal=minHeap.top().first;
            int listNo=minHeap.top().second;
            int maxVal=maxHeap.top();
            minHeap.pop();
            if(maxVal-minVal<minDiff){
                minDiff=maxVal-minVal;
                minv=minVal;
                maxv=maxVal;
            }
            else if(maxVal-minVal==minDiff){
                if(minVal<minv){
                    minv=minVal;
                    maxv=maxVal;
                }
            }
            int nidx=nI[listNo];
            if(nidx<nums[listNo].size()){
                minHeap.push({nums[listNo][nidx],listNo});
                nI[listNo]++;
                maxHeap.push(nums[listNo][nidx]);
            }
            else break;
        }
        
        return {minv,maxv};
    }
};