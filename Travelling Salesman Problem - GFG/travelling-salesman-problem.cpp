// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
int ans=INT_MAX;
void helper(vector<vector<int>>& adj,int ccost,vector<int>& path,vector<bool>& vis){
    if(path.size()==adj.size()){
        //there is path b/w the last vertex and the 0th vertex..
        if(adj[path.back()][0])
        ans=min(ans,ccost+adj[path.back()][0]);
        return;
    }
    
    for(int i=0;i<adj.size();i++){
        if(adj[path.back()][i] and !vis[i]){
            vis[i]=true;
            int nc=ccost+adj[path.back()][i];
            path.push_back(i);
            helper(adj,nc,path,vis);
            vis[i]=false;
            path.pop_back();
        }
    }
}
int total_cost(vector<vector<int>>cost){
    // Code here
    vector<int> path;
    vector<bool> vis(cost.size(),false);
    path.push_back(0);
    vis[0]=true;
    helper(cost,0,path,vis);
    return ans==INT_MAX? 0: ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends