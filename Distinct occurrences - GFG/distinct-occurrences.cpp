// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int dp[8001][101];
    int helper(string s,string t,int n1,int n2){
        //return the count of distinct occurences of t in s..
        if(n2==0) return 1;  //second string is reduced to "";
        if(n1==0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        if(s[n1-1]==t[n2-1]) return dp[n1][n2]=helper(s,t,n1-1,n2-1)+helper(s,t,n1-1,n2);
        
        return dp[n1][n2]=helper(s,t,n1-1,n2);
        
    }
    int subsequenceCount(string S, string T)
    {
        int n1=S.size(),n2=T.size();
        long dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n1;i++) dp[i][0]=1;  //case of empty string..
        
        int mod=1000000007;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(S[i-1]==T[j-1]){
                    dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
                }
                else dp[i][j]=dp[i-1][j]%mod;
            }
        }
        
        return dp[n1][n2]%mod;
      //Your code here
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends