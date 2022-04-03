class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int toBeInStack=max(0,k-((int)nums.size()-i));
            
            while(ans.size() and ans.size()>toBeInStack and ans.back()>num){
                ans.pop_back();
            }
            if(ans.size()<k) ans.push_back(num);
        }
        return ans;
    }
};