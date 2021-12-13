class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;
        int winSize=k+1;
        /*
            -t=<nums[i]-nums[j]<=t
            nums[j]-t<=nums[i]<nums[j]+t;
        */
        for(int i=0;i<nums.size();i++){
            if(i>=winSize) st.erase(nums[i-winSize]);
            auto it=st.lower_bound((long)nums[i]-t);
            if(it!=st.end() and *it<=(long)nums[i]+t)
                return true;
            st.insert((long)nums[i]);
        }
        return false;
    }
};