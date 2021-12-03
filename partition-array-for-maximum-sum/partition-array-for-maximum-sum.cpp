class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int dp[n];
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int maxVal=INT_MIN;
            int maxm=arr[i];
            for(int j=i;j>=max(0,i-(k-1));j--){
                maxm=max(maxm,arr[j]);
                maxVal=max(maxVal,(i-j+1)*maxm+(j? dp[j-1]: 0));
            }
            dp[i]=maxVal;
        }
        return dp[n-1];
    }
};