// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends


class Solution
{
    public:
    void merge(int arr[], int temp[] , int l, int m, int r)
    {
         int i=l,j=m+1,k=l;
         //1,2,3,4   -> m=(0+3)/2 = 1
         //  m
         //i   j
         //l
         //k
         while(i<=m and j<=r){
             if(arr[i]<=arr[j]){
                 temp[k++]=arr[i++];
             }
             else temp[k++]=arr[j++];
         }
         while(i<=m) temp[k++]=arr[i++];
         while(j<=r) temp[k++]=arr[j++];
         
         for(int i=l;i<=r;i++) arr[i]=temp[i];
    }
    public:
    
    void sort(int arr[],int temp[],int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            sort(arr,temp,l,mid);
            sort(arr,temp,mid+1,r);
            merge(arr,temp,l,mid,r);
        }
    }
    void mergeSort(int arr[], int l, int r)
    {
        int n=r-l+1;
        int temp[n];
        memset(temp,0,sizeof(temp));
        sort(arr,temp,l,r);
        //code here
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends