// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool hamPath(vector<vector<bool>>& adj,vector<bool>& used, vector<int>& path, int V){
        if(path.size()==V) return true;
        
        for(int i=0;i<V;i++){
            if(!used[i] and adj[path.back()][i]){
                used[i]=true;
                path.push_back(i);
                if(hamPath(adj,used,path,V)) return true;
                path.pop_back();
                used[i]=false;
            }
        }
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<vector<bool>> adj(N,vector<bool> (N,false));
        for(vector<int>& e: Edges){
            int st=e[0],end=e[1];
            st--; end--;
            adj[st][end]=true;
            adj[end][st]=true;
        }
        
        for(int i=0;i<N;i++){
            vector<bool> vis(N,false);
            vector<int> path;
            path.push_back(i);
            vis[i]=true;
            if(hamPath(adj,vis,path,N)) return true;
        }
        // code here
        return false;
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