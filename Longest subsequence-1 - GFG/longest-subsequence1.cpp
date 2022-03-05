// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int arr[])
    {
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<N;i++){
            m[arr[i]]=max(m[arr[i]],1);
            if(m.count(arr[i]-1)) m[arr[i]]=max(m[arr[i]],1+m[arr[i]-1]);
            if(m.count(arr[i]+1)) m[arr[i]]=max(m[arr[i]],1+m[arr[i]+1]);
            ans=max(ans,m[arr[i]]);
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends