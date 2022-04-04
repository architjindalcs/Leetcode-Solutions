class Solution {
public:
    int merge(vector<int>& nums,vector<int>& temp, int l,int r,int m){
        int cnt=0,n1=m-1+1,n2=r-m;
        int i=l,j=m+1,k=l;
        
        while(i<=m and j<=r){
            if(nums[i]<=(2*(long)nums[j])){
                i++;
            }
            else{
                cnt+=(m-i+1);
                j++;
            }
        }
        i=l,j=m+1,k=l;
        while(i<=m and j<=r){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else temp[k++]=nums[j++];
        }
        while(i<=m) temp[k++]=nums[i++];
        while(j<=r) temp[k++]=nums[j++];
        
        
        for(int i=l;i<=r;i++) nums[i]=temp[i];
        
        return cnt;
    }
    int helper(vector<int>& nums,vector<int>& temp,int l,int r){
        if(l>=r) return 0;
        int m=(l+r)/2;
        int ans=0;
        ans+=helper(nums,temp,l,m);
        ans+=helper(nums,temp,m+1,r);
        ans+=merge(nums,temp,l,r,m);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size(),0);  
    //    for(int i: nums) cout<<i<<" ";
      //  cout<<endl;
        return helper(nums,temp,0,nums.size()-1);
    }
};