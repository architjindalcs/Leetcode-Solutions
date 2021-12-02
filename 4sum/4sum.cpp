class Solution {
public:
    vector<vector<int>> kSum(vector<int>& nums,int idx,int target,int k){
       
        if(k==2){
            //the problem has been reduced to two sum..
            vector<vector<int>> ans;
            int l=idx,r=nums.size()-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==target){
                    ans.push_back({nums[l],nums[r]});
                    int ele1=nums[l];
                    while(l<r and nums[l]==ele1) l++;
                    int ele2=nums[r];
                    while(l<r and nums[r]==ele2) r--;
                    
                }
                else if(sum<target) l++;
                else r--;
            }
            return ans;
        }
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=idx;i<n-k+1;i++)
        {
            if(i>idx and nums[i]==nums[i-1]) continue;
            vector<vector<int>> next=kSum(nums,i+1,target-nums[i],k-1);
            for(auto v: next){
                vector<int> temp;
                temp.push_back(nums[i]);
                for(int i: v) temp.push_back(i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=3) return {};
        sort(nums.begin(),nums.end());
        return kSum(nums,0,target,4);
    }
};