// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int bitsAreInAltOrder(long long int n){
        // code here
        //1010
        //0101
        //101
        //010
        return  (n ^ (n<<1))==0;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.bitsAreInAltOrder(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends