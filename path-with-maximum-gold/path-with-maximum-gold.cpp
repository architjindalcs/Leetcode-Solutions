class Solution {
public:
    int helper(vector<vector<int>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        int ans=grid[x][y];
        grid[x][y]=0;
        int maxm=0;
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy])
                maxm=max(maxm,helper(grid,newx,newy));
        }
        grid[x][y]=ans;
        return maxm+ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j])
                    ans=max(ans,helper(grid,i,j));
            }
        }
        return ans;
    }
};