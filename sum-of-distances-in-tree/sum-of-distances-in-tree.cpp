class Solution {
public:
    vector<int> cnt;
    vector<int> dist;
    void dfs1(vector<int> adj[],int src,int par){
        cnt[src]=1;
        for(int i: adj[src]){
            if(i==par) continue;
            dfs1(adj,i,src);
            dist[src]+=dist[i]+cnt[i];
            cnt[src]+=cnt[i];
        }
    }
    void dfs2(vector<int> adj[],int src,int par){
        for(int i: adj[src]){
            if(i==par) continue;
            dist[i]=(dist[src]-cnt[i])+(cnt.size()-cnt[i]);
            dfs2(adj,i,src);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        cnt=vector<int>(n,0);
        dist=vector<int>(n,0);
        vector<int> adj[n];
        for(vector<int>& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs1(adj,0,-1);
        dfs2(adj,0,-1);
        return dist;
    }
};