class Solution {
public:
    vector<int> indices;
    vector<int> ans;
    void merge(vector<int>& nums,int l,int r,int m){
        int n1=m-l+1,n2=r-m;
        int L[n1],R[n2];
        for(int i=0;i<n1;i++) L[i]=indices[l+i];
        for(int i=0;i<n2;i++) R[i]=indices[m+1+i];
        int i=0,j=0,k=l;
        int cnt=0;
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
        while(i<n1) {
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
            merge(nums,l,r,m);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) indices.push_back(i);
        ans=vector<int> (nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};