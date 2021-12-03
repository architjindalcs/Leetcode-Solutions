class Solution {
public:
    int numTeams(vector<int>& nums) {
        set<int> lset;
        set<int> rset(nums.begin(),nums.end());
        int res=0;
        for(int i=1;i<nums.size();i++){
            lset.insert(nums[i-1]);
            rset.erase(nums[i-1]); 
            //CASE 1 -> nums[i]<nums[j]<nums[k];
            //1,2, 3
            int d1=distance(lset.begin(),lset.lower_bound(nums[i]));
            int d2=distance(rset.upper_bound(nums[i]),rset.end());
            if(d1 > 0 && d2 > 0)
                res += d1*d2;
            
            int d3 = std::distance(lset.upper_bound(nums[i]), lset.cend()); 
            int d4 = std::distance(rset.cbegin(), rset.lower_bound(nums[i])); 
            if(d3 > 0 && d4 > 0)
                res += d3*d4; 
        }
        return res;
    }
};