class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                if(i+1<nums.size()) m[nums[i+1]]++;
            }
        }
        int maxf=0,ans;
        for(auto x: m){
            if(x.second>maxf){
                maxf=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};