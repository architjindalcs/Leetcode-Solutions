class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        grid[x][y]=1;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]==0)
                dfs(grid,newx,newy);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            if(grid[i][0]==0) dfs(grid,i,0);
            if(grid[i][c-1]==0) dfs(grid,i,c-1);
        }
        for(int i=0;i<c;i++){
            if(grid[0][i]==0) dfs(grid,0,i);
            if(grid[r-1][i]==0) dfs(grid,r-1,i);
        }
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);  
                    cnt++;
                }
            }
        }
        return cnt;
    }
};