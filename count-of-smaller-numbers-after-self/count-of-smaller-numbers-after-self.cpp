class Solution {
public:
    vector<int> indices;
    vector<int> ans;
    
    //0,1,2,3  -> m=1 n1=2 n2=3-1=2
    
    void merge(vector<int>& nums,int l,int r,int m){
        int n1=m-l+1;
        int n2=r-m;
        int L[n1],R[n2];
        for(int i=0;i<n1;i++) L[i]=indices[l+i];
        for(int i=0;i<n2;i++) R[i]=indices[m+1+i];
        
        int i=0,j=0,k=l,cnt=0;
        while(i<n1 and j<n2){
            if(nums[L[i]]<=nums[R[j]]){
                indices[k++]=L[i];
                ans[L[i]]+=cnt;
                i++;
            }
            else{
                indices[k++]=R[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
            indices[k++]=L[i];
            ans[L[i]]+=cnt;
            i++;
        }
        while(j<n2) indices[k++]=R[j++];
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
        
        int n=nums.size();
        ans=vector<int>(n,0);
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};