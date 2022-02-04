// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{

    public:
        vector<int> ans;
        vector<int> lpshelper(string pat){
            int i=1,len=0;
            int m=pat.size();
            vector<int> lps(m,0);
            while(i<m){
                if(pat[i]==pat[len]){
                    lps[i]=1+len;
                    i++;
                    len++;
                }
                else{
                    if(len) len=lps[len-1];
                    else i++;
                }
            }
            return lps;
        }
        
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int> lps=lpshelper(pat);
            int i=0,j=0;
            int n=txt.size(),m=pat.size();
            while(i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(j) j=lps[j-1];
                    else i++;
                }
                if(j==pat.size()){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
            }
            if(ans.empty()) return {-1};
            return ans;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends