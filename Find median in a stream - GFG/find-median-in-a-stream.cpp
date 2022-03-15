// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    void insertHeap(int &x)
    {
        if(maxHeap.empty() or x<maxHeap.top()){
            maxHeap.push(x);
        }
        else minHeap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int n1=minHeap.size(),n2=maxHeap.size();
        if(n1-n2>1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(n2-n1>1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int n1=minHeap.size(),n2=maxHeap.size();
        if(n1==n2){
            return (minHeap.top()+maxHeap.top())/2.0;
        }
        else if(n1>n2) return minHeap.top();
        return maxHeap.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends