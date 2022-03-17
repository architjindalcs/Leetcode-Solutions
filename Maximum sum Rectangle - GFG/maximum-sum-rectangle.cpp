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
        for(int col=1;col<c;col++){
            for(int row=0;row<r;row++)
            grid[row][col]+=grid[row][col-1];
        }

        for(int stcol=0;stcol<c;stcol++){
           
            for(int endcol=stcol;endcol<c;endcol++){
                int cs=0;
                for(int i=0;i<r;i++){
                    int ele=grid[i][endcol]-(stcol? grid[i][stcol-1]: 0);
                  //  cout<<"ele:  "<<ele<<endl;
                    cs=max(cs+ele,ele);
                    
                    ans=max(ans,cs);
                    }
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