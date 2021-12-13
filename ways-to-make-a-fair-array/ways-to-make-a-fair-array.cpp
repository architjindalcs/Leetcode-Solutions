class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int esum=0,osum=0,pesum=0,posum=0;
        for(int i=0;i<nums.size();i++){
            if(i&1) osum+=nums[i];
            else esum+=nums[i];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) esum-=nums[i];
            else osum-=nums[i];
            if(esum+posum==pesum+osum){
                ans++;
            }
            pesum+=(i%2==0? nums[i]: 0);
            posum+=(i%2==1? nums[i]: 0);
        }
        return ans;
    }
};