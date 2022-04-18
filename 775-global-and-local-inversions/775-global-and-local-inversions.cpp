class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        /*
            Each local inversion is global inversion, 
            but each global inversion is not local inversion
            so if global<=local and local==global -> there are only local
            inversions in array..
        */
        for(int i=0;i<nums.size();i++){
            if(abs(i-nums[i])>1) return false;
        }
        return true;
    }
};