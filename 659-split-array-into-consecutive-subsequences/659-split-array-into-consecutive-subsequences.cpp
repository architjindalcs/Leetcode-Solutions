class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> hm,fm;
        for(int num: nums) fm[num]++;
        
        for(int num: nums){
            if(!fm[num]) continue;
            if(hm[num]){
                fm[num]--;
                hm[num]--;
                hm[num+1]++;
            }
            else{
                if(fm[num] and fm[num+1] and fm[num+2]){
                    hm[num+3]++;
                    fm[num]--;
                    fm[num+1]--;
                    fm[num+2]--;
                }
                else return false;
            }
        }
        return true;
    }
};