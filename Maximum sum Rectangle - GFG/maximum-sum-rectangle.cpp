// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int r, int c, vector<vector<int>>& grid) {
        // code here
        int ans=INT_MIN;
        
        for(int i=0;i<r;i++){
            vector<int> arr(c,0);
            for(int j=i;j<r;j++){
                for(int col=0;col<c;col++)
                arr[col]+=grid[j][col];
                
                int cs=0;
                for(int k=0;k<arr.size();k++){
                    cs=max(cs+arr[k],arr[k]);
                    ans=max(ans,cs);
                }
                
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends