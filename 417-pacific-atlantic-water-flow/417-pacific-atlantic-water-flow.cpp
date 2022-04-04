class Solution {
public:
    vector<vector<bool>> vis1;
    vector<vector<bool>> vis2;
    void dfs1(vector<vector<int>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        vis1[x][y]=true;
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]>=grid[x][y]){
                if(!vis1[newx][newy])
                    dfs1(grid,newx,newy);
            }
        }
    }
    void dfs2(vector<vector<int>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        vis2[x][y]=true;
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]>=grid[x][y]){
                if(!vis2[newx][newy])
                    dfs2(grid,newx,newy);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vis1=vector<vector<bool>>(r,vector<bool>(c,false));
        vis2=vector<vector<bool>>(r,vector<bool>(c,false));
        
        for(int i=0;i<r;i++) dfs1(grid,i,0);
        for(int j=0;j<c;j++) dfs1(grid,0,j);
        

        for(int i=0;i<r;i++) dfs2(grid,i,c-1);
        for(int j=0;j<c;j++) dfs2(grid,r-1,j);
        vector<vector<int>> ans;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(vis1[i][j] and vis2[i][j]) ans.push_back({i,j});
        return ans;
    }
};