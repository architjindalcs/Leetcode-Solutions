// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<string> ans;
	void permute(string s,int idx){
	    if(idx==s.size()){
	        ans.push_back(s);
	        return;
	    }
	    for(int i=idx;i<s.size();i++){
	        swap(s[i],s[idx]);
	        permute(s,idx+1);
	    //    swap(s[i],s[idx]);
	    }
	}
	vector<string>find_permutation(string S)
	{
	    permute(S,0);
	    sort(ans.begin(),ans.end());
	    return ans;
	    // Code here there
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends