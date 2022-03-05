// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<pair<int,int>> v;
        for(int i=0;i<N-1;i++) v.push_back({arr[i],arr[i+1]});
        N=v.size();
        int dp[N][N];
        memset(dp,0,sizeof(dp));
        for(int l=2;l<=N;l++){
            for(int i=0;i<=(N-l);i++){
                int k=i+l-1;
                /*
                 (40,20),(20,30),(30,10),(10,30)
                  i                        k
                                   z
                */
                
                int minOps=INT_MAX;
                for(int z=i;z<=k-1;z++){
                    // cout<<v[i].first<<" "<<v[i].second<<endl;
                    minOps=min(minOps,dp[i][z]+dp[z+1][k]+((v[i].first)*(v[z].second)*(v[k].second)));
                }
                dp[i][k]=minOps;
            }
        }
        return dp[0][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends