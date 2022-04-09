class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int num: nums)m[num]++;
        auto cmp=[&](pair<int,int>& p1,pair<int,int>& p2){
          return p1.second>p2.second;  
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        
        for(auto x: m){
            if(pq.size()<k) pq.push({x.first,x.second});
            else{
                if(pq.top().second<x.second){
                    pq.pop();
                    pq.push({x.first,x.second});
                }
            }
        }
        //vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};