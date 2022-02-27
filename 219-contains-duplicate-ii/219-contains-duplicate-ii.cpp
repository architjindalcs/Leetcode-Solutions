class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
            abs(i-j)<=k
            -k <= (i-j) <= k
            (j-k)<=i<=(j+k)
        */
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i]) and m[nums[i]]>=(i-k)) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};