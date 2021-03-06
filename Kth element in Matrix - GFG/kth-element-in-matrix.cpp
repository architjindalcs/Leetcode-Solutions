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
int kthSmallest(int grid[MAX][MAX], int n, int k)
{
    vector<int> nI(n,1);
    
    int cnt=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i=0;i<n;i++){
        pq.push({grid[i][0],i});
    }
    
    while(pq.size()){
        pair<int,int> tp=pq.top();
        pq.pop();
        int ele=tp.first,listNo=tp.second;
        cnt++;
        if(cnt==k) return ele;
        
        int nidx=nI[listNo];
        
        if(nidx<n){
            pq.push({grid[listNo][nidx],listNo});
            nI[listNo]++;
        }
    }
    
    return -1;
  //Your code here
}
