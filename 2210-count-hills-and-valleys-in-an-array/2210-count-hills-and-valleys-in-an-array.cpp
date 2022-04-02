class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt=0,ans=0;
        
        unordered_set<string> st;
        for(int i=0;i<nums.size();i++){
            if(i and nums[i]==nums[i-1]) continue;
            int leftUneq=-1,rightUneq=-1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]!=nums[j]) {
                    leftUneq=j;
                    break;
                }
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j]){
                    rightUneq=j;
                    break;
                }
            }
            
            if(leftUneq==-1 or rightUneq==-1) continue;
            if(nums[leftUneq]>nums[i] and nums[rightUneq]>nums[i]){
               ans++;
                // st.insert(to_string(nums[leftUneq])+"#"+to_string(nums[rightUneq]));
            }
            
            if(nums[leftUneq]<nums[i] and nums[rightUneq]<nums[i]){
                ans++;
                //st.insert(to_string(nums[leftUneq])+"#"+to_string(nums[rightUneq]));
            }
           // if()
        }
        return ans;
    }
};