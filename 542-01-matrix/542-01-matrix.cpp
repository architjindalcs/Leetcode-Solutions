class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!grid[i][j]) {
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        vector<vector<int>> ans(r,vector<int>(c,0));
        int level=0;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                pair<int,int> fr=q.front();
                q.pop();
                int x=fr.first,y=fr.second;
                ans[x][y]=level;
                for(int k=0;k<4;k++){
                    int newx=x+row[k],newy=y+col[k];
                    if(newx>=0 and newx<r and newy>=0 and newy<c and !vis[newx][newy]){
                        vis[newx][newy]=true;
                        q.push({newx,newy});
                    }
                }
            }
            level++;
        }
        return ans;
    }
};