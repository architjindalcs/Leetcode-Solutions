class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        grid[x][y]='O';
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]=='-'){
                dfs(grid,newx,newy);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(grid[i][j]=='O') grid[i][j]='-';
        for(int i=0;i<r;i++){
            if(grid[i][0]=='-') dfs(grid,i,0);
            if(grid[i][c-1]=='-') dfs(grid,i,c-1);
        }
        
        for(int i=0;i<c;i++){
            if(grid[0][i]=='-') dfs(grid,0,i);
            if(grid[r-1][i]=='-') dfs(grid,r-1,i);
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='-') grid[i][j]='X';
            }
        }
    }
};