class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int pro=1;
        ans[0]=pro;
        for(int i=1;i<nums.size();i++){
            pro*=nums[i-1];
            ans[i]=pro;
        }
        int next=nums.back();
        for(int i=n-2;i>=0;i--){
            ans[i]*=next;
            next*=nums[i];
        }
        return ans;
    }
};