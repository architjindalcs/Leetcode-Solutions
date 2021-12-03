class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> temp;
            int num=i,idx=0;
            while(num){
                int bit=num&1;
                num=num/2;
                if(bit) temp.push_back(nums[idx]);
                idx++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};