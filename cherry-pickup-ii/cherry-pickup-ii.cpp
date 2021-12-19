class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int dp[r][c][c];
        memset(dp,0,sizeof(dp));
        for(int i=r-1;i>=0;i--){
            for(int c1=0;c1<c;c1++){
                for(int c2=0;c2<c;c2++){
                    dp[i][c1][c2]=(c1==c2? grid[i][c1]: grid[i][c1]+grid[i][c2]);
                    if(i==r-1) continue;
                    int maxm=0;
                    for(int dx=-1;dx<=1;dx++){
                        for(int dy=-1;dy<=1;dy++){
                            int nc1=c1+dx,nc2=c2+dy;
                            if(nc1>=0 and nc1<c and nc2>=0 and nc2<c) 
                                maxm=max(maxm,dp[i+1][nc1][nc2]);
                        }
                    }
                    dp[i][c1][c2]+=maxm;
                }
            }
        }
        return dp[0][0][c-1];
    }
};