// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long gcd2(long long A,long long B){
        if(A==0) return B;
        if(B==0) return A;
        
        if(A==B) return A;
        if(A>B) return gcd2(A-B,B);
        return gcd2(A,B-A);
    }
    long long gcd(long long A,long long B){
        if(B==0) return A;
        //Time complexity is O(log(max(A,B)));
        return gcd(B,A%B);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> ans;
        long long gc=gcd2(A,B);
        long long lc=((A*B)/gc);
        return {lc,gc};
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends