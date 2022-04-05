class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> all;
        for(vector<int>& v: matches) {
            all.insert(v[0]);
            all.insert(v[1]);
        }
        unordered_set<int> allwin=all;
        unordered_map<int,int> flose;
        
        for(vector<int>& v: matches){
            if(allwin.count(v[1])) allwin.erase(v[1]);
            flose[v[1]]++;
        }
        
        vector<vector<int>> ans;
        ans.push_back(vector<int> (allwin.begin(),allwin.end()));
        
        vector<int> v;
        for(auto x: flose)
            if(x.second==1) v.push_back(x.first);
        
        ans.push_back(v);
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
        
    }
};