class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& grid,int x,int y,int px,int py){
        int r=grid.size(),c=grid[0].size();
        if(dp[x][y]!=0) return dp[x][y];
        int ans=0;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]>grid[x][y] 
              and !(newx==px and newy==py)){
                ans=max(ans,helper(grid,newx,newy,x,y));
            }
        }
        return dp[x][y]=(ans+1);
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        dp=vector<vector<int>> (r,vector<int> (c,0));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=max(ans,helper(grid,i,j,-1,-1));
            }
        }
        return ans;
    }
};