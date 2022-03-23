class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        //unordered_map<int,int> dp[n];
        
        int dp[n][2100];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                int d=nums[i]-nums[j]+1000;
                int clen=2;
                if(dp[j][d]){
                    clen=1+dp[j][d];
                }
                dp[i][d]=max(dp[i][d],clen);
                ans=max(ans,dp[i][d]);
            }
        }
        return ans;
    }
};