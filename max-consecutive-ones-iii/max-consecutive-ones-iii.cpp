class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //longest subarray with atmost k zeros..
        int i=0,cz=0,st=0;
        int ans=0;
        while(i<nums.size()){
            cz+=(nums[i]==0);
            while(st<i and cz>k){
                cz-=(nums[st]==0);
                st++;
            }
            if(cz<=k)
            ans=max(ans,i-st+1);
            i++;
        }
        return ans;
    }
};