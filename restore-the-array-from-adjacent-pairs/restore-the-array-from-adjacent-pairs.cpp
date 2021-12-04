class Solution {
public:
    vector<int> ans;
    void dfs(unordered_map<int,vector<int>>& adj,int src,vector<int>& path,int par){
        path.push_back(src);
        if(path.size()==adj.size() and ans.empty()){
            ans=path;
            return;
        }
        if(ans.size()) return;
        for(int j: adj[src]){
            if(j==par) continue;
            dfs(adj,j,path,src);
        }
        path.pop_back();
        
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> deg;
        for(vector<int>& v: adjacentPairs){
            int st=v[0],end=v[1];
            adj[st].push_back(end);
            adj[end].push_back(st);
            deg[st]++;
            deg[end]++;
        }
        int src=-1;
        for(auto x: deg) {
            if(x.second==1) {
                //agr degree=1 h toh, that will be the src vertex..set src=x.first;
                src=x.first;
                break;
            }
        }
        vector<int> path;
        dfs(adj,src,path,INT_MIN);
        return ans;
    }
};