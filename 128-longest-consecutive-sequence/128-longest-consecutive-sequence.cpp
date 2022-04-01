class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int num: nums){
            if(st.count(num-1)) continue;
            int clen=0;
            int ele=num;
            while(st.count(ele)){
                clen++;
                ele++;
            }
            ans=max(ans,clen);
        }
        return ans;
    }
};