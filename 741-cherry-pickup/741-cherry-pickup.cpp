class Solution {
public:
    int dp[51][51][51];
    int helper(vector<vector<int>>& grid,int x1,int y1,int x2){
        int r=grid.size(),c=grid[0].size();
        int y2=x1+y1-x2;  
        if(!(x1<r and x2<r and y1<c and y2<c and grid[x1][y1]!=-1 and grid[x2][y2]!=-1))
            return INT_MIN;
        if(dp[x1][y1][x2]!=-1) return dp[x1][y1][x2];
        if(x1==r-1 and y1==c-1) return grid[x1][y1];
        
        int curr=(x1!=x2? grid[x1][y1]+grid[x2][y2]: grid[x1][y1]);;
   
        
        int maxm=INT_MIN;

        
        maxm=max(maxm,helper(grid,x1+1,y1,x2+1)); //DD
        maxm=max(maxm,helper(grid,x1+1,y1,x2));  //DR
        maxm=max(maxm,helper(grid,x1,y1+1,x2+1));  //RD
        maxm=max(maxm,helper(grid,x1,y1+1,x2));  //RR
        
        
        if(maxm==INT_MIN) //not reachable..
            return dp[x1][y1][x2]=INT_MIN;
        return dp[x1][y1][x2]=maxm+curr;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        
        return max(0,helper(grid,0,0,0));
    }
};