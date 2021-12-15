class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        grid[x][y]=0;
        for(int k=0;k<4;k++){
            int newx=x+row[k];
            int newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy])
                dfs(grid,newx,newy);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            if(grid[i][0]) dfs(grid,i,0);
            if(grid[i][c-1]) dfs(grid,i,c-1);
        }
        for(int j=0;j<c;j++){
            if(grid[0][j]) dfs(grid,0,j);
            if(grid[r-1][j]) dfs(grid,r-1,j);
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                   ans+=1;
                }
            }
        }
        return ans;
        
    }
};