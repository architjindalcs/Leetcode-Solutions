class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int cs=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            cs+=(nums[i]? 1: -1);
            if(cs==0) ans=i+1;
            if(m.count(cs)) ans=max(ans,i-m[cs]);
            else m[cs]=i;
        }
        return ans;
    }
};