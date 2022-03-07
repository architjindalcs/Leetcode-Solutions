// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	     int row[]={0,0,1,-1};
	    int col[]={1,-1,0,0};
	    int r=grid.size(),c=grid[0].size();
	    vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(grid[i][j]==1){
	                dist[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    int level=0;
	    while(q.size()){
	        int siz=q.size();
	        while(siz--){
	            pair<int,int> fr=q.front(); q.pop();
	            int x=fr.first,y=fr.second;
	            dist[x][y]=level;
	            for(int k=0;k<4;k++){
	                int newx=x+row[k],newy=y+col[k];
	                if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]==0){
	                    grid[newx][newy]=1;
	                    q.push({newx,newy});
	                }
	            }
	        }
	        level++;
	    }
	    return dist;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends