class Solution {
public:
    vector<vector<int>> ksum(vector<int>& nums,int idx, int target,int k){
        if(nums.size()<k) return {};
        if(k==2){
            vector<vector<int>> ans;
            int l=idx,r=nums.size()-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum<target) l++;
                else if(sum>target) r--;
                else{
                    ans.push_back({nums[l],nums[r]});
                    int ele1=nums[l],ele2=nums[r];
                    while(l<r and nums[l]==ele1) l++;
                    while(l<r and nums[r]==ele2) r--;
                }
            }
            return ans;
        }
        
        vector<vector<int>> ans;
        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1]) continue;
            vector<vector<int>> nans=ksum(nums,i+1,target-nums[i],k-1);
            for(vector<int>& v: nans){
                vector<int> temp;
                temp.push_back(nums[i]);
                for(int i: v) temp.push_back(i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return ksum(nums,0,target,4);
    }
};