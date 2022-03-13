// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        for(int i=0;i<arr.size();i++){
            if(abs(arr[i])-1<arr.size() and arr[abs(arr[i])-1]>0)
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0) return i+1;
        }
        return arr.size()+1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends