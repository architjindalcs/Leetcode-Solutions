// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int countPS(string s)
    {
        /*
        */
        int n=s.size();
        long long int dp[n][n];
        int mod=1000000007;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int k=i+l-1;
                if(l==2){
                    dp[i][k]=(s[i]==s[k]? 3 : 2);
                }
                else{
                    if(s[i]==s[k]){
                        /*
                        dp[i][k]=dp[i+1][k]+dp[i][k-1]-dp[i+1][k-1];
                        //a _____ a
                        dp[i][k]++;  //for aa -> new subsequence generated..
                        dp[i][k]+=(dp[i+1][k-1]); //for a[___]a -> middles ones everyone to be included
                        */
                        dp[i][k]=(dp[i+1][k]%mod+dp[i][k-1]%mod+1)%mod;
                    }
                    else{
                        dp[i][k]=(dp[i+1][k]%mod+dp[i][k-1]%mod-dp[i+1][k-1]%mod+mod)%mod;
                    }
                }
            }
        }
        return dp[0][n-1]%mod;
       //Your code here
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends