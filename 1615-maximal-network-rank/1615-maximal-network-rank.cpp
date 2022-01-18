class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int deg[n];
        bool adj[n][n];
        memset(adj,false,sizeof(adj));
        memset(deg,0,sizeof(deg));
        for(vector<int>& v: roads){
            deg[v[0]]++;
            deg[v[1]]++;
            adj[v[0]][v[1]]=adj[v[1]][v[0]]=true;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,deg[i]+deg[j]-adj[i][j]);
            }
        }
        return ans;
    }
};