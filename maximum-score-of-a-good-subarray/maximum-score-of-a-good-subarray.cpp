class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minm=nums[k],i=k,j=k,res=nums[k];
        do{
            if(i>0 and j<nums.size()-1){
                if(nums[i-1]>=nums[j+1])
                    i--;
                else 
                    j++;
            }
            else if(i==0 and j<nums.size()-1){
                j++;
            }
            else if(j==nums.size()-1 and i>0){
                i--;
            }
            minm=min(minm,min(nums[i],nums[j]));
            res=max(res,(j-i+1)*minm);
        }
        while(i>0 or j<nums.size()-1);
        return res;
    }
};