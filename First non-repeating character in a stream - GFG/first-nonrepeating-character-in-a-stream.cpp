// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans="";
		    queue<char> q;
		    unordered_map<char,int> f;
		    for(char ch: A){
		        f[ch]++;
		        q.push(ch);
		        while(q.size() and f[q.front()]>1){
		            q.pop();
		        }
		        if(q.size()) ans+=(q.front());
		        else ans+="#";
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends