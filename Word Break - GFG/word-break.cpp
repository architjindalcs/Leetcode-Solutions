// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> st(B.begin(),B.end());
        bool dp[A.size()];
        memset(dp,false,sizeof(dp));
        dp[0]=st.count(A.substr(0,1));
        string cs=string(1,A[0]);
    //    cout<<"cs: "<<cs<<endl;
        for(int i=1;i<A.size();i++){
            cs+=A[i];
            if(st.count(cs)) dp[i]=true;
            if(dp[i]) continue;
            for(int j=i-1;j>=0;j--){
                if(dp[j] and st.count(A.substr(j+1,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[A.size()-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends