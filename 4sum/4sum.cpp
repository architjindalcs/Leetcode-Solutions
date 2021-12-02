class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=3) return {};
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++){
            if(i and nums[i]==nums[i-1]) continue; //case of repetition..
            if((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>(long)target) break;
            if((long)nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<(long)target) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                if((long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>(long)target) break;
                if((long)nums[i]+nums[j]+nums[n-2]+nums[n-1]<(long)target) continue;
                int l=j+1,r=n-1;
                while(l<r){
                    int sum=nums[l]+nums[r]+nums[i]+nums[j];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<nums.size() and nums[l]==nums[l-1]) l++;
                        while(r>l and nums[r]==nums[r+1]) r--;
                    }
                    else if(sum<target) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};