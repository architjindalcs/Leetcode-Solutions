class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<k;i++) ans.push_back(nums[i]);
        for(int j=k;j<nums.size();j++){
            int minm=INT_MAX,minIdx=-1;
            for(int i=0;i<ans.size();i++){
                if(ans[i]<minm){
                    minm=ans[i];
                    minIdx=i;
                }
            }
            if(nums[j]<minm) continue;
            ans.erase(ans.begin()+minIdx);
            ans.push_back(nums[j]);
        }
        return ans;
    }
};