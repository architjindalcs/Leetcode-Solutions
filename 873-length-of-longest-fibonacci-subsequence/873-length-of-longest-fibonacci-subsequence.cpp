class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //sort(arr.begin(),arr.end());
        int n=arr.size();
        int dp[n][n]; //dp[i][j] -> longest fib ending j
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=2;i<n;i++){
            int l=0,r=i-1;
            
            while(l<r){
                int sum=arr[l]+arr[r];
                if(sum<arr[i]) l++;
                else if(sum>arr[i]) r--;
                else{
                    //sum==arr[i];
                    dp[r][i]=max(dp[r][i],1+dp[l][r]);
                    ans=max(ans,dp[r][i]);
                    l++;
                    r--;
                }
            }
        }
        return ans==0? 0: ans+2;
    }
};