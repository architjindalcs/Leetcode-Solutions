class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        bool vis[r][c];
        memset(vis,false,sizeof(vis));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=true;
                    grid[i][j]=0;
                }
            }
        }
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        int level=0;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first,y=p.second;
                grid[x][y]=level;
                for(int k=0;k<4;k++){
                    int newx=x+row[k],newy=y+col[k];
                    if(newx>=0 and newx<r and newy>=0 and newy<c and !vis[newx][newy]){
                        q.push({newx,newy});
                        vis[newx][newy]=true;
                    }
                }
            }   
            level++;
        }
        return grid;
    }
};