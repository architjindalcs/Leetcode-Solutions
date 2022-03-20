// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends



int helper(int grid[MAX][MAX], int n,int mid){
    int cnt=0;
    //returns cnt of elements <= mid;
    for(int i=0;i<n;i++){
        auto it=upper_bound(grid[i],grid[i]+n,mid);
        cnt+=(it-grid[i]);
    }
    return cnt;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int st=mat[0][0],end=mat[n-1][n-1];
    while(st<end){
        int mid=(st+end)/2;
        int cnt=helper(mat,n,mid);
        if(cnt>=k){
            end=mid;
        }
        else st=mid+1;
    }
    return st;
  //Your code here
}
