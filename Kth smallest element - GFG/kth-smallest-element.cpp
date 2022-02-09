// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition_r(vector<int>& nums,int low,int high){
        if(low==high) return low;
        int ridx=(low+(rand()%(high-low)));
        //low= 0, high=3;
        swap(nums[high],nums[ridx]);
        return partition(nums,low,high);
    }
    int partition(vector<int>& nums,int low,int high){
        int pivot=nums[high];
        int st=low-1;
        for(int i=low;i<=high-1;i++){
            if(nums[i]<=pivot){
                swap(nums[++st],nums[i]);
            }
        }
        swap(nums[st+1],nums[high]);
        return st+1;
    }
    int qs(vector<int>& nums,int l,int r,int k){
        if(l>r) return INT_MAX;
        int pidx=partition_r(nums,l,r);
        if(pidx==k) return nums[pidx];
        else if(pidx<k){
            return qs(nums,pidx+1,r,k);
        }
        else{
            return qs(nums,l,pidx-1,k);   
        }
        return -1;
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n=r-l+1;
        vector<int> v;
        for(int i=l;i<=r;i++) v.push_back(arr[i]);
    
        return qs(v,0,v.size()-1,k-1);
        
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends