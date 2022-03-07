// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> adj[],int src,vector<bool>& vis,stack<int>& st){
	    vis[src]=true;
	    for(int i: adj[src]){
	        if(!vis[i]){
	            dfs(adj,i,vis,st);
	        }
	    }
	    st.push(src);
	}
	void dfs2(vector<int> adj[],int src,vector<bool>& vis){
	    vis[src]=true;
	    for(int i: adj[src]){
	        if(!vis[i]){
	            dfs2(adj,i,vis);
	        }
	    }
	}
	void reverse(vector<int> adj[],int V,vector<int> newadj[]){
	    for(int i=0;i<V;i++){
	        for(int j: adj[i]){
	            newadj[j].push_back(i);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(adj,i,vis,st);
        }
        
        vis=vector<bool> (V,false);
        vector<int> newadj[V];
        reverse(adj,V,newadj);
        
        int ans=0;
        while(st.size()){
            int tp=st.top();
            st.pop();
            if(vis[tp]) continue;
            dfs2(newadj,tp,vis);
            ans++;
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends