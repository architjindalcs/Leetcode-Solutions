class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
       int sum=0;
        for(int i: nums) sum+=i;
        int pz=0,po=0;
        int maxm=0;
        vector<int> ans;
        for(int i=0;i<=nums.size();i++){
            int score=pz+(sum-po);
            if(score>maxm){
                maxm=score;
                ans.clear();
                ans.push_back(i);
            }
            else if(score==maxm) ans.push_back(i);
            if(i==nums.size()) continue;
            pz+=(nums[i]==0);
            po+=(nums[i]==1);
        }
    
        return ans;
    }
};