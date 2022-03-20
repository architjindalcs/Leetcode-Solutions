// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */

class Solution {
    public:
        int isValid(string s) {
            int n=s.size();
            if(!(n>=4 and n<=15)) return false;
            int cntDots=0;
            s+=".";
            string cs="";
            for(char& ch: s){
                if(!((ch>='0' and ch<='9') or (ch=='.'))) return false;
                if(ch==':') return false;
                
                if(ch=='.'){
                    cntDots++;
                    if(cs.empty()) return false;
                    if(cs.size()>3) return false;
                    if(cs[0]=='0' and cs.size()!=1) return false;
                    
                    int val=stoi(cs);
                    if(!(val>=0 and val<=255)) return false;
                    cs="";
                }
                else cs+=ch;
            }
            return cntDots==4;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends