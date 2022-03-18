// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        // code here
        //1 0 0 0 1
        //    R L
        //0 0 1 1 0;
        int ones=R-L+1;
        
        int mask = (1<<ones)-1;
        mask = mask << (L-1);
        
        return N ^ mask;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends