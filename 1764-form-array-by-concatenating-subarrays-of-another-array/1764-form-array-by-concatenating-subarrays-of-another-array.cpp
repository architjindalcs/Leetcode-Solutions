class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i=0;
        int gidx=0;
        while(gidx<groups.size()){
            if(i==nums.size()) return false;
            if(nums[i]!=groups[gidx][0]) {
                i++;
                continue;
            }
            int lenGrp=groups[gidx].size();
            if(!(i+lenGrp-1<=nums.size()-1)) return false;
            bool check=true;
            int j=i;
            int sidx=0;
            while(j<nums.size() and sidx<groups[gidx].size()){
                if(nums[j]!=groups[gidx][sidx]){
                    check=false;
                    break;
                }
                j++;
                sidx++;
            }
            if(!check){
                i++;
                continue;
            }
            else{
                gidx++;
                i=j;
            }
        }
        return gidx==groups.size();
    }
};