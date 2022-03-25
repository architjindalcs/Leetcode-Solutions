// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int V;
    bool hamPath(vector<vector<bool>>& adj,vector<bool>& vis,vector<int>& path){
        if(path.size()==adj.size()){
            //covered all vertices..hamiltonian path case..
            return true;
        }
        
        for(int i=0;i<adj.size();i++){
            if(!vis[i] and adj[path.back()][i]){
                vis[i]=true;
                path.push_back(i);
                if(hamPath(adj,vis,path)) return true;
                path.pop_back();
                vis[i]=false;
            }
        }
        return false;
        
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<vector<bool>> adj(N,vector<bool>(N,false));
        for(auto& e: Edges){
            int st=e[0],end=e[1];
            st--; end--;
            adj[st][end]=true;
            adj[end][st]=true;
        }
        for(int i=0;i<N;i++){
            vector<int> path;
            path.push_back(i);
            vector<bool> vis(N,false);
            vis[i]=true;
            if(hamPath(adj,vis,path)) return true;
        }
        return false;
        // code here
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends