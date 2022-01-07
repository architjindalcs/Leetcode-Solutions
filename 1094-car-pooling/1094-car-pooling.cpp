class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int dp[1001];
        memset(dp,0,sizeof(dp));
        for(vector<int>& t: trips){
            int np=t[0],st=t[1],end=t[2];
            dp[st]+=np;
            dp[end]-=np;
        }
        for(int i=1;i<=1000;i++) dp[i]+=dp[i-1];
        for(int i=0;i<=1000;i++) if(dp[i]>capacity) return false;
        
        return true;
    }
};