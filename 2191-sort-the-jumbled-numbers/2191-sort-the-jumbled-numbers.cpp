class Solution {
public:
    int getVal(vector<int>& map,int num){
        if(num==0) return map[num];
        int ans=0;
        int mulf=1;
        while(num){
            ans=ans+(mulf*map[num%10]);
            mulf*=10;
            num/=10;
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end(),[&](pair<int,int>& p1,pair<int,int>& p2){
           int num1=p1.first,num2=p2.first;
           int idx1=p1.second,idx2=p2.second;
           int val1=0,val2=0;
           num1=getVal(mapping,num1);
           num2=getVal(mapping,num2);
            if(num1<num2)
                return true;
            else if(num1>num2) return false;
            return idx1<idx2;
        });
        vector<int> ans;
        for(pair<int,int>& p: v){
            ans.push_back(nums[p.second]);
        }
        return ans;
    }
};