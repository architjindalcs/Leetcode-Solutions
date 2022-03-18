// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int countSubstringWithEqualEnds(string s)
	{
	    int cnt[26],ans=0;
	    memset(cnt,0,sizeof(cnt));
	    for(int i=0;i<s.size();i++){
	        ans+=(cnt[s[i]-'a']);
	        cnt[s[i]-'a']++;
	        ans++;
	    }
	    return ans;
	    // Your code goes here
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   	    Solution ob;

   		cout << ob.countSubstringWithEqualEnds(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends