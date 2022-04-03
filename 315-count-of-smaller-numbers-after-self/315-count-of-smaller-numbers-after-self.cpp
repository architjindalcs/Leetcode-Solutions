class Solution {
public:
    vector<int> indices;
    vector<int> ans;
    
    void merge(vector<int>& nums,int l,int m,int r){
        int n1=m-l+1,n2=r-m;
        int L[n1],R[n2];
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        
        for(int i=0;i<n1;i++) L[i]=indices[l+i];
        for(int i=0;i<n2;i++) R[i]=indices[m+1+i];
        
        int cnt=0;
        
        int i=0,j=0,k=l;
        while(i<n1 and j<n2){
            if(nums[L[i]]<=nums[R[j]]){
                ans[L[i]]+=cnt;
                indices[k++]=L[i++];
            }
            else{
                cnt++;
                indices[k++]=R[j++];
            }
        }
        
        while(i<n1){
            ans[L[i]]+=cnt;
            indices[k++]=L[i++];
        }
        while(j<n2){
            indices[k++]=R[j++];
        }
    }
    void mergeSort(vector<int>& nums,int l,int r){
        if(l<r){
            int m=(l+r)/2;
            mergeSort(nums,l,m);
            mergeSort(nums,m+1,r);
            merge(nums,l,m,r);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        indices=vector<int> (n,0);
        for(int i=0;i<indices.size();i++) indices[i]=i;
        ans=vector<int> (n,0);
        mergeSort(nums,0,n-1);
        return ans;
    }
};