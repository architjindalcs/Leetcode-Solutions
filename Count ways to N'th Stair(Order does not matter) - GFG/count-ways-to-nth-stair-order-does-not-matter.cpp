// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    int dp[n+1];
		    for(int i=0;i<=n;i++) dp[i]=1;
		    for(int i=2;i<=n;i++) dp[i]+=dp[i-2];
		    return dp[n];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends