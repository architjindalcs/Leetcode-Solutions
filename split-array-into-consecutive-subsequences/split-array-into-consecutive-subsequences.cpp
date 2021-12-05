class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> hm;
        unordered_map<int,int> fm;
        for(int i: nums) fm[i]++;
        
        for(int i: nums){
            if(!fm[i]) continue;  //we dont have this number..
            if(hm[i]){
                fm[i]--;
                hm[i]--;
                hm[i+1]++;
            }
            else{
                if(fm[i] and fm[i+1] and fm[i+2]){
                    //forming a new subsequence...
                    fm[i]--; fm[i+1]--; fm[i+2]--;
                    hm[i+3]++;
                }
                else return false;
            }
        }
        return true;
    }
};