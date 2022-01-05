class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=31;i>=0;i--){
            int set=0,unset=0;
            for(int num: nums){
                if(num&(1<<i)) set++;
                else unset++;
            }
            ans+=(set*unset);
        }
        return ans;
    }
    
};