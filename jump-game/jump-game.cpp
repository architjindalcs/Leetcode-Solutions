class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        int cnt=1,ladder=nums[0],stair=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1) return true;
            ladder=max(ladder,i+nums[i]);
            stair--;
            if(stair<=0){
                cnt++;
                stair=ladder-i;
                if(stair<=0) return false;
            }
        }
        return false;
    }
};