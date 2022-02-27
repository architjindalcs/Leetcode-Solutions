// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    vector<bool> processQueries(int arr[], int n, vector<pair<int, int>> &queries,
                                int q) {
         vector<int> left(n);
        vector<int> right(n);
        left[0]=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                left[i]=i;
            }
            else left[i]=left[i-1];
        }
        
        
        right[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                right[i]=i;
            }
            else right[i]=right[i+1];
        }
        vector<bool> ans;
        for(auto& q: queries){
            int st=q.first,end=q.second;
            if(left[end]<=right[st]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}  // } Driver Code Ends