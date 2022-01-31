// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //n-> size of first array, m-> size of second array..
        if(n>m)
        return kthElement(arr2,arr1,m,n,k);
        
        int st=max(0,k-m),end=min(k,n);
        
        while(st<=end){
            int cut1=(st+end)/2;
            int cut2=k-cut1;
            int l1=cut1? arr1[cut1-1]: INT_MIN;
            int l2=cut2? arr2[cut2-1]: INT_MIN;
            int r1=cut1<n? arr1[cut1]: INT_MAX;
            int r2=cut2<m? arr2[cut2]: INT_MAX;
            if(l1<=r2 and l2<=r1) return max(l1,l2);
            else if(l1>r2){
                end=cut1-1;
            }
            else st=cut1+1;
        }
        return -1;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends