class Solution {
public:
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y,int t){
        int r=grid.size(),c=grid[0].size();
        if(x==r-1 and y==c-1) return true; //we have reached the destination..
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        if(grid[x][y]>t) return false;
        visited[x][y]=true;
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]<=t and !visited[newx][newy]){
               if(dfs(grid,visited,newx,newy,t)) return true; 
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int st=0,end=2500;
        int ans=-1;
        int r=grid.size(),c=grid[0].size();
        while(st<=end){
            int mid=(st+end)/2;
            vector<vector<bool>> visited(r,vector<bool>(c,false));
            if(dfs(grid,visited,0,0,mid)){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};