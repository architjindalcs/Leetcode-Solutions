class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,ele1=-1,ele2=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else if(cnt1==0){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0){
                cnt2=1;
                ele2=nums[i];
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int f1=0,f2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) f1++;
            else if(nums[i]==ele2) f2++;
        }
        int n=nums.size();
        vector<int> ans;
        if(f1>n/3) ans.push_back(ele1);
        if(f2>n/3) ans.push_back(ele2);
        
        return ans;
        
    }
};