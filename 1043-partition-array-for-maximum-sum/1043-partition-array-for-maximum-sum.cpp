class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=arr[0]; //single element case..
        
        //0,1,2,3
        //      i
        for(int i=1;i<n;i++){
            int mtn=arr[i];
            int maxPoss=INT_MIN;
            for(int j=i;j>=max(0,i-k+1);j--){
                mtn=max(mtn,arr[j]);
                maxPoss=max(maxPoss,mtn*(i-j+1)+ (j? dp[j-1] : 0));
            }
            dp[i]=maxPoss;
        }
        return dp[n-1];
    }
};