class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        pair<int,int> dp[n][n];
        for(int i=0;i<n;i++)
            dp[i][i]={piles[i],0};
        for(int len=2;len<=n;len++){
            for(int i=0;i<=(n-len);i++){
                int k=i+len-1;
                int cf=piles[i]+dp[i+1][k].second;
                int cl=piles[k]+dp[i][k-1].second;
                if(cf>cl)
                    dp[i][k]={cf,dp[i+1][k].first};
                else
                    dp[i][k]={cl,dp[i][k-1].first};
            }
        }
        return dp[0][n-1].first>dp[0][n-1].second;
    }
};