// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int arr[], int n, int amt) {
        long long int dp[amt+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++){
            int ele=arr[i];
            for(int i=ele;i<=amt;i++)
            dp[i]+=dp[i-ele];
        }
        return dp[amt];
        // code here.
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends