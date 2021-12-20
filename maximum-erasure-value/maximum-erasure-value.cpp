class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //maximum sum subarray with unique elements..
        int cs=0,i=0,st=0,ans=0; 
        unordered_map<int,int> m;
        while(i<nums.size()){
            cs+=nums[i];
            m[nums[i]]++;
            while(st<i and m.size()<(i-st+1)){
                cs-=nums[st];
                m[nums[st]]--;
                if(m[nums[st]]==0) m.erase(nums[st]);
                st++;
            }
            if(m.size()==(i-st+1)){
                ans=max(ans,cs);
            }
            i++;
        }
        return ans;
    }
};