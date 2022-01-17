class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        sort(nums.begin(),nums.end());
        int idx=0;
        for(int i=0;i<n;i+=2) 
        ans[i]=nums[idx++];
        
        for(int i=1;i<n;i+=2)
            ans[i]=nums[idx++];
        return ans;
    }
};