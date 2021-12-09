class Solution {
public:
    vector<int> suff;
    vector<vector<int>> dp;
    int helper(vector<int>& piles,int idx,int M){
        if(idx==piles.size()) return 0;
        int end=idx+2*M-1;
        if(end>=piles.size()-1) return suff[idx]; //alice can them all..haha
        if(dp[idx][M]!=-1) return dp[idx][M];
        
        int minm=INT_MAX;
        for(int x=1;x<=2*M;x++){
            minm=min(minm,helper(piles,idx+x,max(M,x)));
        }
        return dp[idx][M]=(suff[idx]-minm);
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp=vector<vector<int>> (n,vector<int>(n,-1));
        suff=vector<int> (n,0);
        suff[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--)
            suff[i]=piles[i]+suff[i+1];
        return helper(piles,0,1);
    }
};