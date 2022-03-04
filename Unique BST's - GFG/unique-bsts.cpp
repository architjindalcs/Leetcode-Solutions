// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        if(N<=2) return N;
        // Your code here
        if(N==1) return 1; 
        long dp[N+1];
        int mod=1000000007;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=N;i++){
            int left=0;
            while(left<=(i-1)){
                int right=i-1-left;
                dp[i]=(dp[i]%mod + (dp[left]%mod*dp[right]%mod)%mod)%mod;
                left++;
            }
        }
        return dp[N]%mod;
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends