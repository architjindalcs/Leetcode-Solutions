class Solution {
public:
    queue<pair<int,int>> q;
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        grid[x][y]=0;
        q.push({x,y});
        vis[x][y]=true;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k];
            int newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]){
                dfs(grid,newx,newy);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int r=grid.size(),c=grid[0].size();
        bool go=true;
        vis=vector<vector<bool>>(r,vector<bool>(c,false));
        for(int i=0;i<r and go;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    dfs(grid,i,j);
                    go=false;
                    break;
                }
            }
        }
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        int level=0;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                pair<int,int> fr=q.front();
                q.pop();
                int x=fr.first,y=fr.second;
                for(int k=0;k<4;k++){
                    int newx=x+row[k],newy=y+col[k];
                    if(newx>=0 and newx<r and newy>=0 and newy<c and !vis[newx][newy]){
                        if(grid[newx][newy]==1) return level;
                        vis[newx][newy]=true;
                        q.push({newx,newy});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};