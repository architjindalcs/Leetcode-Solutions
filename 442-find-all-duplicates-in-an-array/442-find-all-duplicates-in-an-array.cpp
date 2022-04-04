class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        /*
           a -> a+bn 
         
        */
        int maxm=nums.size()+1;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i]%maxm;
            int idx=ele-1;
            nums[idx]+=maxm;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]/maxm>1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};