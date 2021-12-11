class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int dp[366];
        memset(dp,0,sizeof(dp));
        unordered_set<int> st(days.begin(),days.end());
        for(int i=1;i<=365;i++){
            if(!st.count(i)) {
                dp[i]=dp[i-1];
                continue;
            }
            int odp=costs[0]+(i>=1? dp[i-1]: 0);
            int sdp=costs[1]+(i>=7? dp[i-7]: 0);
            int tdp=costs[2]+(i>=30? dp[i-30]: 0);
            dp[i]=min(odp,min(sdp,tdp));
        }
        return dp[365];
    }
};