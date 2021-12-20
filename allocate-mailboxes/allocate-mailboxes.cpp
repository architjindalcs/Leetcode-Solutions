class Solution {
public:
    vector<vector<int>> cost;
    int dp[101][101];
    int helper(vector<int>& houses,int idx,int k){
        if(k==0 and idx==houses.size())
            return 0;
        if(k==0 or idx==houses.size()) return 10000000; 
        if(dp[idx][k]!=-1) return dp[idx][k];
        int minm=10000000;
        for(int i=idx;i<houses.size();i++){
            minm=min(minm,cost[idx][i]+helper(houses,i+1,k-1));
        }
        return dp[idx][k]=minm;
    }
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        memset(dp,-1,sizeof(dp));
        cost=vector<vector<int>> (n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int midIdx=(i+j)/2;
                for(int k=i;k<=j;k++)
                    cost[i][j]+=abs(houses[k]-houses[midIdx]);
            }
        }
        return helper(houses,0,k);
        //now I have the cost matrix..cost[i][j] -> denotes the cost, if i put a mailbox, 
        //
    }
};