class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n=nums.size(),s=0;
        while(s<n-1 and nums[s]<=nums[s+1]) s++;
        if(s==n-1) return 0; //the array is already sorted..
        int e=n-1;
        while(e>0 and nums[e]>=nums[e-1]) 
            e--;
        int ans=min(n-1-s,e);
        int i=0,j=e;
        while(i<=s and j<n){
            if(nums[i]<=nums[j]){
                i++;
                ans=min(ans,(j-1-(i)+1));
            }
            else j++;
        }
        return ans;
    }
};