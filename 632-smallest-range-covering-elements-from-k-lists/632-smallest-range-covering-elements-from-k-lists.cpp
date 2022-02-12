class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<int> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > minHeap;
        int k=nums.size();
        vector<int> nI(k,1);
        for(int i=0;i<k;i++){
            minHeap.push({nums[i][0],i});
            maxHeap.push(nums[i][0]);
        }
        int minDiff=INT_MAX;
        int minv,maxv;
        while(minHeap.size()){
            pair<int,int> fr=minHeap.top();
            minHeap.pop();
            int nodeVal=fr.first;
            int listNo=fr.second;
            int minVal=nodeVal;
            int maxVal=maxHeap.top();
            if(maxVal-minVal<minDiff){
                minDiff=maxVal-minVal;
                minv=minVal;
                maxv=maxVal;
            }
            
            int nidx=nI[listNo];
            if(nidx<nums[listNo].size()){
                minHeap.push({nums[listNo][nidx],listNo});
                maxHeap.push(nums[listNo][nidx]);
                nI[listNo]++;
            }
            else break;
        }
        return {minv,maxv};
        
    }
};