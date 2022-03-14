class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums.size()<4) return {};
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++){
            //1,2,3,4 -> i<1
            if(i>0 and nums[i]==nums[i-1]) continue;
            if((long)nums[i]+(long)nums[i+1]+(long)nums[i+2]+(long)nums[i+3]>target) break;
            if((long)nums[i]+(long)nums[n-1]+(long)nums[n-2]+(long)nums[n-3]<target) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;               
                if((long)nums[i]+(long)nums[j]+(long)nums[j+1]+(long)nums[j+2]>target) break;
                if((long)nums[i]+(long)nums[j]+(long)nums[n-2]+(long)nums[n-1]<target) continue;  
                int l=j+1,r=nums.size()-1;
                while(l<r){
                    int sum=nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum<target)
                        l++;
                    else if(sum>target)
                        r--;
                    else{
                      //  cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int ele1=nums[l],ele2=nums[r];
                        while(l<r and nums[l]==ele1) l++;
                        while(l<r and nums[r]==ele2) r--;
                    }
                }
            }
        }
        return ans;
    }
};