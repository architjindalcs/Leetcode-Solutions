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
	    vector<int> temp=nums;
	    sort(temp.begin(),temp.end());
	    
	    int cnt=0;
	    unordered_map<int,int> m;
	    for(int i=0;i<nums.size();i++) m[nums[i]]=i;
	    
	    for(int i=0;i<nums.size();i++){
	        if(nums[i]==temp[i]) continue;
        
            cnt++;	        
	        int tbidx=m[temp[i]];
	        swap(nums[i],nums[tbidx]);
	        swap(m[nums[i]],m[nums[tbidx]]);
	    }
	    return cnt;
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