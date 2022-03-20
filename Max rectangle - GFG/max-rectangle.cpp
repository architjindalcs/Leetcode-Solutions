// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int histo(vector<int>& nums){
        stack<int> st;
        int n=nums.size();
        int maxm=0;
        for(int i=0;i<=nums.size();i++){
            while(st.size() and (i==nums.size() or nums[st.top()]>=nums[i])){
                int tpIdx=st.top();  //curr height index in consideration..
                st.pop();
                int prevSmaller=(st.size()? st.top(): -1);
                int nextSmaller=i;
                
                maxm=max(maxm, nums[tpIdx] * (nextSmaller-prevSmaller-1));
            }
            st.push(i);
        }
        return maxm;
    }
    int maxArea(int grid[MAX][MAX], int r, int c) {
        // Your code here
        vector<int> v;
        for(int i=0;i<c;i++) v.push_back(grid[0][i]);
        int ans=histo(v);
        
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++) {
                if(grid[i][j]) v[j]++;
                else v[j]=0;
            }
            ans=max(ans,histo(v));
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends