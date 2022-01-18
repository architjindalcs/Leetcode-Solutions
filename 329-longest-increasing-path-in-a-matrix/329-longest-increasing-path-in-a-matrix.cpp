class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& grid,int x,int y){
        int r=grid.size(),c=grid[0].size();
        if(dp[x][y]) return dp[x][y];
        int ans=1;
        int maxm=0;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]>grid[x][y]){
                maxm=max(maxm,helper(grid,newx,newy));
            }
        }
        return dp[x][y]=1+maxm;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        dp=vector<vector<int>> (r,vector<int>(c,0));
        int maxm=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                maxm=max(maxm,helper(grid,i,j));
            }
        }
        return maxm;
    }
};