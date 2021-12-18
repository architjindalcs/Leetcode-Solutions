class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int dp[1001];
        memset(dp,0,sizeof(dp));
        for(vector<int>& v: trips){
            int np=v[0], st=v[1],end=v[2]-1;
            dp[st]+=np;
            dp[end+1]-=np;
        }
        for(int i=1;i<=1000;i++) dp[i]+=dp[i-1];
        for(int i=0;i<=1000;i++) 
            if(dp[i]>capacity) return false;
        return true;
    }
};