// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {
        int meh[n];
        int cs=0;
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){
            cs=max(cs+A[i],A[i]);
            meh[i]=cs;
            maxm=max(maxm,cs);
        }
        
        int prev=0;
        for(int i=n-1;i>=0;i--){
            int sum=(prev+(i? meh[i-1]: 0));
            maxm=max(maxm,sum);
            prev=max(A[i],prev+A[i]);
        }
        return maxm;
        //Your code here
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		Solution obj;
		cout<<obj.maxSumSubarray(a,n)<<endl;
	}
}

  // } Driver Code Ends