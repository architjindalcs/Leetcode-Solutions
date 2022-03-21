class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans=1;
        for(int i=0;i<arr.size();i++){
            if(dp.count(arr[i]-difference))
                dp[arr[i]]=max(dp[arr[i]],1+dp[arr[i]-difference]);
            if(!dp.count(arr[i])) dp[arr[i]]=1;
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};