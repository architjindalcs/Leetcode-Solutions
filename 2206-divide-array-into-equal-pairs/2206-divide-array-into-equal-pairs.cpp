class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>  m;
        for(int i: nums) m[i]++;
        for(auto x: m){
            if(x.second&1) return false;
        }
        return true;
    }
};