// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({start[i],end[i]});
        sort(v.begin(),v.end(),[&](pair<int,int>& p1,pair<int,int>& p2){
           return p1.second<p2.second; 
        });
        int ans=1;
        int pst=v[0].first,pend=v[0].second;
        for(int i=1;i<v.size();i++){
            if(v[i].first>pend){
                ans++;
                pst=v[i].first; pend=v[i].second;
            }
        }
        return ans;
        // Your code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends