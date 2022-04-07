class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<nums.size();i++){
            if(i%2==1) odd.push_back(nums[i]);
            else  even.push_back(nums[i]);
        }
    
        int eidx=0;
        sort(odd.begin(),odd.end(),greater<int>()); sort(even.begin(),even.end());
        for(int ele: even){
            nums[eidx]=ele;
            eidx+=2;
        }
        int oidx=1;
        for(int ele: odd){
            nums[oidx]=ele;
            oidx+=2;
        }
        return nums;
    }
};