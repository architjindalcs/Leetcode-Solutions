// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    bool vis[n];
	    int ans=0;
	    memset(vis,false,sizeof(vis));
	    vector<pair<int,int>> arrPos;
	    for(int i=0;i<nums.size();i++) arrPos.push_back({nums[i],i});
	    sort(arrPos.begin(),arrPos.end());
	    for(int i=0;i<n;i++){
	        if(nums[i]==arrPos[i].first or vis[i]) continue;
	        int j=i;
	        int cnt=0;
	        while(!vis[j]){
	            vis[j]=true;
	            j=arrPos[j].second;
	            cnt++;
	        }
	        ans+=(cnt-1);
	    }
	    return ans;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends