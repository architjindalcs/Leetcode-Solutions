// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
                vector<vector<int>> gp(V,vector<int>(V,0));
        for(int i=0;i<V;i++){
            for(auto& v: adj[i]){
                gp[i][v[0]]=v[1];
                gp[v[0]][i]=v[1];
            }
        }
        int parent[V];
        memset(parent,-1,sizeof(parent));
        bool inMST[V];
        memset(inMST,false,sizeof(inMST));
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({dist[0],0});
        // code here
        while(pq.size()){
            int frNode=pq.top().second;
            pq.pop();
            inMST[frNode]=true;
            for(vector<int>& p: adj[frNode]){
                int nodeVal=p[0], wt=p[1];
                if(dist[nodeVal]>wt and !inMST[nodeVal]){
                    dist[nodeVal]=wt;
                    parent[nodeVal]=frNode;
                    pq.push({dist[nodeVal],nodeVal});
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            if(parent[i]!=-1){
                ans+=(gp[i][parent[i]]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends