// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    string reduce(string& p){
        string ans="";
        int n=p.size(),i=0;
        while(i<n){
            char ch=p[i];
            if(ch!='*'){
                ans+=p[i++];
                continue;
            }
            while(i<n and p[i]=='*') i++;
            ans+="*";
        }
        return ans;
    }
/*You are required to complete this method*/
    int wildCard(string p,string s)
    {
        p=reduce(p);
        int n=s.size(),m=p.size();
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;   //empty string and empty pattern is there..so total match is there..
        if(p[0]=='*') dp[0][1]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] or p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] or dp[i][j-1];
                }
                else dp[i][j]=false;
            }
        }
        //string = "abc" pattern =
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends