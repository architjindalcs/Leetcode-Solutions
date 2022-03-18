// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
	int maxRepeating(int *arr, int n, int k) {
	    // code here
	    for(int i=0;i<n;i++){
	        int idx=(arr[i]%k);
	        arr[idx]+=(k);
	    }
	    
	    int maxf=0,maxm=-1;
	    for(int i=0;i<n;i++){
	        int f=(arr[i]/k);
	        if(f>maxf){
	            maxf=f;
	            maxm=i;
	        }
	        else if(maxf==f and i<maxm) {
	            maxm=i;
	        }
	    }
	    return maxm;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxRepeating(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends