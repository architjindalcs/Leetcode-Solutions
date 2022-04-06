class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long ans=0;
        int mod=1000000007;
        for(int i=0;i<nums.size();i++){
      //      if(i and nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum<target) l++;
                else if(sum>target) r--;
                else{
                    //
                    /*
                    
                         1 1 1 3 3 3 
                    
                    */
                    if(nums[l]==nums[r]){
                        //kind of 1,1,1,1,1
                        long cnt=r-l+1;  //choose 2 out of it 1,1,1 
                        ans=(ans%mod + ((cnt*(cnt-1))/2)%mod)%mod;
                        break;
                        //return ans;
                    }
                    else{
                        //1,1,1,3,3,3
                        int ele1=nums[l]; long cnt1=0;
                        int ele2=nums[r]; long cnt2=0;
                        while(l<r and nums[l]==ele1) {
                            cnt1++;
                            l++;
                        }
                        while(l<=r and nums[r]==ele2){
                            cnt2++;
                            r--;
                        }
                        ans=(ans%mod+(cnt1%mod*cnt2%mod)%mod)%mod;
                    }   
                }
            }
        }
        return ans%mod;
    }
};