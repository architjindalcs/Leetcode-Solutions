class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       /*
          nums[i] < nums[k] < nums[j];
          i < j < k
       */
        int candK=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<candK) return true;
            while(st.size() and nums[st.top()]<nums[i]){
                candK=nums[st.top()];
                st.pop();
            }
            st.push(i);
        }
        return false;
    }
};