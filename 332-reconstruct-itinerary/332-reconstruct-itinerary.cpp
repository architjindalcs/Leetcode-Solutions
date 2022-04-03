class Solution {
public:
    vector<string> ans;
    void dfs(string src,unordered_map<string,vector<string>>& adj){
        while(adj[src].size()){
            string back=adj[src].back();
            adj[src].pop_back();
            dfs(back,adj);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,vector<string>> adj;
        for(vector<string>& v: tickets){
            string st=v[0],end=v[1];
            adj[st].push_back(end);
        }
        for(auto& x: adj){
            vector<string> v=x.second;
            sort(v.begin(),v.end(),greater<string>());
            adj[x.first]=v;
        }

        dfs("JFK",adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};