class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_set<int> st;
        vector<int> ans(k,0); //ans[i] -> cnt of users, with uam=i;
        unordered_map<int,unordered_set<int>> m;
        for(vector<int>& l: logs)
            m[l[0]].insert(l[1]);
        for(auto x: m){
            int uam=x.second.size();
            if(uam<=k) ans[uam-1]++;
        }
        return ans;
    }
};