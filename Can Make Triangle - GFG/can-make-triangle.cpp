// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    bool valid(int a,int b,int c){
        return a+b>c and b+c>a and c+a>b;
    }
    vector<int> canMakeTriangle(vector<int> A, int N){
        // code 
        vector<int> ans;
        int ele1=A[0],ele2=A[1],ele3=A[2];
        if(valid(ele1,ele2,ele3)) ans.push_back(1);
        else ans.push_back(0);
        for(int i=3;i<N;i++){
            //1   2   3   4
//            e1  e2  e3  e4

            ele1=ele2;
            ele2=ele3;
            ele3=A[i];
            if(valid(ele1,ele2,ele3)) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends