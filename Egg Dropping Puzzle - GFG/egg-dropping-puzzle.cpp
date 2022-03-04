// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int f) 
    {
        // your code here
        int dp[e+1][f+1];
        memset(dp,0,sizeof(dp));
        //case of one egg..
        for(int i=1;i<=f;i++) dp[1][i]=i;
        //case of one floor..
        for(int i=1;i<=e;i++) dp[i][1]=1;
        
        for(int ee=2;ee<=e;ee++){
            for(int ff=2;ff<=f;ff++){
                int minAttempts=INT_MAX;
                for(int tf=1;tf<=ff;tf++){
                    int tutgya=dp[ee-1][tf-1];
                    int nhituta=dp[ee][ff-tf];
                    minAttempts=min(minAttempts,1+max(tutgya,nhituta));
                }
                dp[ee][ff]=minAttempts;
            }
        }
        return dp[e][f];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends