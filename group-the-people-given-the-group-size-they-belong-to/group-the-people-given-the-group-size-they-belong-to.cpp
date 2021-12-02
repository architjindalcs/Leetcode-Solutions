class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        unordered_map<int,vector<vector<int>>> m;    
        int idx=0;
        for(int gsize: groupSizes){
            if(m[gsize].empty() or m[gsize].back().size()==gsize)
                m[gsize].push_back({idx});
            else m[gsize].back().push_back(idx);
            idx++;
        }
        vector<vector<int>> ans;
        for(auto x: m) for(vector<int> v: x.second) ans.push_back(v);
        return ans;
    }
};