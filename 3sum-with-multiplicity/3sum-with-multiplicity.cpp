class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int mod=1000000007;
        sort(nums.begin(),nums.end());
        
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum=nums[l]+nums[r]+nums[i];
                if(sum<target) l++;
                else if(sum>target) r--;
                else{
                    if(nums[l]==nums[r]){
                        //saare elements in equal h..
                        long long f=(long long)r-l+1;
                        ans=(ans%mod+(f*(f-1)/2)%mod)%mod;
                        break;
                    }
                    else{
                        //cout<<"l: "<<l<<", r: "<<r<<endl;
                        long long cnt1=0,cnt2=0;
                        int ele1=nums[l],ele2=nums[r];
                        while(l<r and nums[l]==ele1){
                            cnt1++;
                            l++;
                        }
                        while(r>=l and nums[r]==ele2){
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