// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(vector<int> adj[],int src,vector<bool>& vis){
        queue<int> q;
        int V=vis.size();
        vector<int> parent(V,-1);
        q.push(src);
        vis[src]=true;
        while(q.size()){
            int fr=q.front();
            q.pop();
            for(int i: adj[fr]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                    parent[i]=fr;
                }
                else if(vis[i] and parent[fr]!=i)
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycle(adj,i,vis)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends