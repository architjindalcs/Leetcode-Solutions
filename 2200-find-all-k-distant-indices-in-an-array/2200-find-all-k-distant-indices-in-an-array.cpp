class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
  //     vector<int> ans;
        /*
            |i-j|<=k and nums[j]==key
        
        */
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                for(int j=max(0,i-k);j<=min((int)nums.size()-1,i+k);j++) st.insert(j);
            }
        }
        vector<int> ans;
        for(auto x: st) ans.push_back(x);
        sort(ans.begin(),ans.end());
        return ans;
    }
};