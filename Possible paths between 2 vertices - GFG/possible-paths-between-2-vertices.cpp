// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
	    vector<int> ts;
	   
	    vector<int> indeg(V,0);
	    for(int i=0;i<V;i++){
	        for(int j: adj[i]) indeg[j]++; 
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0) q.push(i);
	    }
	    while(q.size()){
	        int fr=q.front();
	        q.pop();
	        ts.push_back(fr);
	        for(int j: adj[fr]){
	            if(--indeg[j]==0) q.push(j);
	        }
	    }
	    
	    int dp[V];
	    memset(dp,0,sizeof(dp));
        dp[destination]=1;

       for(int i=ts.size()-1;i>=0;i--){
	        for(int j: adj[ts[i]]){
	            dp[ts[i]]+=dp[j];
	        }
	    }
	    return dp[source];
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