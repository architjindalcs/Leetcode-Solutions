// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector<int> ans;
        vector <int> search(string pat, string txt)
        {
            if(pat.size()>txt.size()){
                return {-1};
            }
            int d=256,pr=101;  //a prime number..
            int n=txt.size(),m=pat.size();
            int t=0,p=0;
            for(int i=0;i<m;i++){
                p=(p*d+pat[i])%pr;
                t=(t*d+txt[i])%pr;  //pr is a prime number 
            }
            int prepower=1;
            for(int i=0;i<m-1;i++){
                prepower=(prepower*d)%pr;
            }
            vector<int> ans;
            for(int i=0;i<=(n-m);i++){
                if(p==t){
                    //check for equality..
                    bool flag=true;
                    int j;
                    for(j=0;j<m and i+j<n;j++){
                        if(txt[i+j]!=pat[j]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag and j==m) 
                    ans.push_back(i+1);    
                }
                if(i<n-m){
                    t=(d*(t-prepower*txt[i])+txt[i+m])%pr;  //txt[i+m] ->is the new char in window
                    if(t<0) t=t+pr;   
                }
            }
            //code hee.
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