class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;
        int winSize=k+1; 
        for(int i=0;i<nums.size();i++){
            if(i>=winSize) st.erase(nums[i-winSize]);
            
            int curr=nums[i];  //[ curr-t , curr+t ], try finding anyone..
            
            auto it = st.lower_bound((long)curr-t);
            
            if(it!=st.end() and *it <= (long)curr+t){
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};