class Solution {
public:
    double knightProbability(int n, int k, int ro, int colum) {
        double dp[k+1][n][n];
        memset(dp,0.0,sizeof(dp));
        int row[]={2,2,-2,-2,1,1,-1,-1};
        int col[]={-1,1,1,-1,-2,2,2,-2};
        dp[0][ro][colum]=1.0;
        for(int mov=1;mov<=k;mov++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<8;k++){
                        int newx=i+row[k],newy=j+col[k];
                        if(newx>=0 and newx<n and newy>=0 and newy<n){
                            dp[mov][newx][newy]+=(dp[mov-1][i][j]);
                        }
                    }
                }
            }
        }
        double ans=0.0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=(dp[k][i][j]);
            }
        }
        return ans/(1.0*pow(8,k));
    }
};