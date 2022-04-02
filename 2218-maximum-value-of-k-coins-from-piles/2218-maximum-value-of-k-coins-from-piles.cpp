class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        
        int dp[n+1][k+1]; //coins ke lie..
        
        memset(dp,0,sizeof(dp));  //dp[0][i] for all i's -> 0 hi hoga, because piles hi nhi h
        //dp[i] [0] for all i's zero hi hoga, coins nhi h 
        
        for(vector<int>& v: piles){
            for(int i=1;i<v.size();i++){
                v[i]+=v[i-1];
            }
        }
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j]; //skipping the current pile completely..
                
                int maxTakeFromPile=min(j,(int)piles[i-1].size()); //maxm that can be taken from pile, j i.e. the coins..
                for(int tfPile=1;tfPile<=maxTakeFromPile;tfPile++){
                    int sum=(piles[i-1][tfPile-1]);
                    dp[i][j]=max(dp[i][j], (sum) + dp[i-1][j-tfPile]);
                }
            }
        }
        return dp[n][k];
        
    }
};