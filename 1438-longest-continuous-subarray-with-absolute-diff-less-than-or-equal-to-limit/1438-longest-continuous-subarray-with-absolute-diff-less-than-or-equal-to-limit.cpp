class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd,mind;
        int st=0,ans=0;
        for(int i=0;i<nums.size();i++){
            while(maxd.size() and nums[i]>nums[maxd.back()]) maxd.pop_back();
            while(mind.size() and nums[i]<nums[mind.back()]) mind.pop_back();
            maxd.push_back(i);
            mind.push_back(i);
            while(st<nums.size() and nums[maxd.front()]-nums[mind.front()]>limit){
                if(st==maxd.front()) maxd.pop_front();
                if(st==mind.front()) mind.pop_front();
                st++;
            }
            
            if(nums[maxd.front()]-nums[mind.front()]<=limit){
                ans=max(ans,i-st+1);
            }
        }
        return ans;
    }
};