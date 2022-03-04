// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    bool dp[sum+1];
	    memset(dp,false,sizeof(dp));
	    dp[0]=true;
	    for(int i=0;i<n;i++){
	        for(int s=sum;s>=arr[i];s--){
	            if(dp[s-arr[i]]) dp[s]=true;
	        }
	    }
	    for(int i=(sum/2);i>=0;i--){
	        if(dp[i]){
	            return abs(sum-2*i);
	        }
	    }
	    return -1;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends