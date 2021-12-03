class Solution {
public:
    int ans=0;
    void helper(vector<vector<int>>& grid,int x,int y,int& cnt){
        int r=grid.size(),c=grid[0].size();
        cnt++;
        grid[x][y]=0;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy])
                helper(grid,newx,newy,cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    int cnt=0;
                    helper(grid,i,j,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};