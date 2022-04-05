class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> indeg,outdeg;
        for(vector<int>& v: matches) {
            outdeg[v[0]]++;
            if(indeg.count(v[0])==0) indeg[v[0]]=0;
            indeg[v[1]]++;
            if(outdeg.count(v[1])==0) outdeg[v[1]]=0;
        }
        vector<vector<int>> ans(2);
        for(auto x: indeg){
            if(x.second==0) ans[0].push_back(x.first);
            if(x.second==1) ans[1].push_back(x.first);
        }
        
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
        
    }
};