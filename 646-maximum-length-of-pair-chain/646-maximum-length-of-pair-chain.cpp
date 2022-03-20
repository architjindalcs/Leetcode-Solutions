class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](vector<int>& v1,vector<int>& v2){
            return v1[1]<v2[1];
        });
        int n=pairs.size();
        int dp[n],ans=1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};