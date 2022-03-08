// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    vector<int> dp;
    int helper(vector<int> adj[],int src,int dest){
        if(src==dest) return 1;
        int cnt=0;
        for(int i: adj[src]){
            if(dp[i]==-1)
            cnt+=helper(adj,i,dest);
            else cnt+=dp[i];
        }
        dp[src]=cnt;
        return cnt;
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        dp=vector<int> (V,-1);  //-1 represents no path from current vertex to destination..
        
        return helper(adj,source,destination);
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends