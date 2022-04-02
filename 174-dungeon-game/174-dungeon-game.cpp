class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int dp[r][c];
        memset(dp,0,sizeof(dp));
        dp[r-1][c-1]=(grid[r-1][c-1]<0? abs(grid[r-1][c-1]) : 0);
        //dp[i][j] = minimum energy at (i,j) required to get to (r-1,c-1) safely..
        
        for(int i=r-2;i>=0;i--){
            //dp[i][c-1]  + grid[i][c-1] >= dp[i+1][c-1] dp[i][c-1] > = dp[i+1][c-1]-grid[i][c-1]
            
            dp[i][c-1]=max(0,dp[i+1][c-1]-grid[i][c-1]);
        }
        
        for(int j=c-2;j>=0;j--){
            dp[r-1][j]=max(0,dp[r-1][j+1]-grid[r-1][j]);
        }
        
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                int moveRight=max(0,dp[i][j+1]-grid[i][j]);
                int moveDown=max(0,dp[i+1][j]-grid[i][j]);
                dp[i][j]=min(moveRight,moveDown);
            }
        }
        return dp[0][0]+1;
    }
};