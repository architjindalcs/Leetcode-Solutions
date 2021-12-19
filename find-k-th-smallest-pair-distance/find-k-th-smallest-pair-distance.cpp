class Solution {
public:
    int cntLTEK(vector<int>& v,int k){
        int ans=0,i=1,j=0;
        while(i<v.size() and j<v.size()){
            if(v[i]-v[j]<=k){
                ans+=(i-j);
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int end=nums.back()-nums[0];
        int st=nums[1]-nums[0];
        for(int i=2;i<nums.size();i++) st=min(st,nums[i]-nums[i-1]);
        while(st<end){
            int mid=(st+(end-st)/2);
            int cnt=cntLTEK(nums,mid);
            if(cnt>=k) end=mid;
            else st=mid+1;
        }
        return st;
    }
};