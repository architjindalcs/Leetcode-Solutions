class Solution {
public:
    int findPaths(int r, int c, int maxMove, int x, int y) {
        long ans=0;
        int mod=1000000007;
        int dp[maxMove+1][r][c];
        memset(dp,0,sizeof(dp));
      //  vector<vector<long>> dp(r,vector<long>(c,0));
        dp[0][x][y]=1;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int mov=1;mov<=maxMove;mov++){
           // vector<vector<long>> temp(r,vector<long>(c,0));
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    for(int k=0;k<4;k++){
                        int newx=i+row[k],newy=j+col[k];
                        if(newx>=0 and newx<r and newy>=0 and newy<c){
                            dp[mov][newx][newy]=(dp[mov][newx][newy]%mod+dp[mov-1][i][j]%mod)%mod;
                        }
                        else ans=(ans%mod+dp[mov-1][i][j]%mod)%mod;
                    }
                }
            }
        
        }
        return ans%mod;
    }
};