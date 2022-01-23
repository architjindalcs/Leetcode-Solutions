class Solution {
public:
    int countElements(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    cnt++;
                    break;
                }
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    cnt++;
                    break;
                }
            }
            ans+=(cnt==2);
        }
        return ans;
    }
};