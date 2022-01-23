class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i: nums) m[i]++;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i]+1) or m.count(nums[i]-1) or m[nums[i]]>1) continue;
            ans.push_back(nums[i]);
        }
        return ans;
    }
};