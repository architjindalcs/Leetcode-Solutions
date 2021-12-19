class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp=[&](pair<int,int>& p1,pair<int,int>& p2){
            return nums1[p1.first]+nums2[p1.second]>nums1[p2.first]+nums2[p2.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(int i=0;i<min((int)nums2.size(),k);i++){
            pq.push({0,i});
        }
        int cnt=0;
        vector<vector<int>> ans;
        while(pq.size()){
            int num1idx=pq.top().first,num2idx=pq.top().second;
            pq.pop();
            ans.push_back({nums1[num1idx],nums2[num2idx]});
            cnt++;
            if(cnt==k) return ans;
            if(num1idx+1<nums1.size()){
                pq.push({num1idx+1,num2idx});
            }
        }
        return ans;
    }
};