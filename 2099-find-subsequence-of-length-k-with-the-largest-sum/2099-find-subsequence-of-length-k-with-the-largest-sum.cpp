class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
            int aageKaSum=0,siz=k-1;
            for(int j=i+1;j<nums.size();j++){
                if(pq.size()<siz){
                    pq.push({nums[j],j});
                    aageKaSum+=nums[j];
                }
                else{
                    aageKaSum+=nums[j];
                    pq.push({nums[j],j});
                    aageKaSum-=pq.top().first;
                    pq.pop();
                }
            }
            
            int tsum=num+aageKaSum;

            if(tsum>maxSum and pq.size()==siz){
                ans.clear();
                maxSum=tsum;
                vector<int> tidx;
                while(pq.size()) {
                    tidx.push_back(pq.top().second);
                    pq.pop();
                }
                tidx.push_back(i);
                sort(tidx.begin(),tidx.end());
                for(int idx: tidx) ans.push_back(nums[idx]);
            }
        }
//        cout<<"maxSum: "<<maxSum<<endl;
        return ans;
    }
};