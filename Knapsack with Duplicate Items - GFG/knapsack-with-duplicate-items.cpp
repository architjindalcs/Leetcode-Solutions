// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
                vector<vector<int>> dp(2,vector<int>(W+1,0));
        for(int w=1;w<=W;w++){
            if(w>=wt[0]){
                dp[0][w]=(w/wt[0])*val[0];
            }
        }
        for(int i=1;i<N;i++){
            for(int w=1;w<=W;w++){
                if(wt[i]>w) dp[i%2][w]=dp[(i-1)%2][w];  //cant chose this itemm..
                else{
                    dp[i%2][w]=max(dp[(i-1)%2][w],val[i]+dp[i%2][w-wt[i]]);
                }
            }
        }
        return dp[(N-1)%2][W];
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends