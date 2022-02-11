class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        vector<int> res;
        for(int ele: nums){
            if(res.empty() or res.back()<ele) 
                res.push_back(ele);
            else{
                int idx=lower_bound(res.begin(),res.end(),ele)-res.begin();
                res[idx]=ele;
            }
        }
        return res.size();
    }
};