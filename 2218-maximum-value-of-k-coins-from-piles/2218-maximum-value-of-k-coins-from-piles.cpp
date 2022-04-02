class Solution {
public:
    int dp[3001][3001];
    int helper(vector<vector<int>>& piles,int idx,int k){
        if(idx==piles.size()) return dp[idx][k]=0;  //invalid case..
        
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        int skip=helper(piles,idx+1,k);
        
        int ans=skip;
        
        int cs=0;
        for(int take=0;take<piles[idx].size() and k-(take+1)>=0;take++){
            cs+=piles[idx][take];
            ans=max(ans,cs+helper(piles,idx+1,k-(take+1)));    
        }
        return dp[idx][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
         return helper(piles,0,k);
    }
};