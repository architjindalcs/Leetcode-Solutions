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
            //left me chote..
            int cnt1=distance(lset.begin(),lset.upper_bound(nums[i]));
            //right me bde jisme element bhi h saath
            int cnt2=distance(rset.find(nums[i]),rset.end())-1;
            
            // int d1=distance(lset.begin(),lset.lower_bound(nums[i])); 
            // int d2=distance(rset.upper_bound(nums[i]),rset.end());
            if(cnt1 > 0 && cnt2 > 0)
                res += cnt1*cnt2;
            
            int d3 = distance(lset.lower_bound(nums[i]), lset.end());  //left be bde..
            int d4 = distance(rset.begin(), rset.find(nums[i])); //right me chote..
            if(d3 > 0 && d4 > 0)
                res += d3*d4; 
        }
        return res;
    }
};