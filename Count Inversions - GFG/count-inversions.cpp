// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
long long merge(long long arr[],long long temp[],int l,int m,int r){
    /*
        1,2,  3,4
          m
          
        1,2,3,    4,5
            m
    */
    long long ans=0;
    int n1=m-l+1;
    int n2=r-m;
    int i=l,j=m+1;
    int k=l;
    
    while(i<=m and j<=r){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            ans+=(m+1-i);
            temp[k++]=arr[j++];
        }
    }
    while(i<=m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];
    
    for(int i=l;i<=r;i++) arr[i]=temp[i];
    return ans;
    
}
long long mergeSort(long long arr[],long long temp[],int st,int end){
    long long ans=0;
    if(st<end){
        int mid=(st+end)/2;
        ans+=(mergeSort(arr,temp,st,mid));
        ans+=(mergeSort(arr,temp,mid+1,end));
        ans+=(merge(arr,temp,st,mid,end));
    }
    return ans;
}
long long inversionCount(long long arr[], long long n)
{
    long long temp[n];
    memset(temp,0,sizeof(temp));
    return mergeSort(arr,temp,0,n-1);
    // Your Code Here
}

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends