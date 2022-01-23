class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int ei=0,oi=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res[ei]=nums[i];
                ei+=2;
            }
            else{
                res[oi]=nums[i];
                oi+=2;
            }
        }
        return res;
    }
};