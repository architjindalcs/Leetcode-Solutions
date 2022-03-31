class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=0;i<n;i++) nums.push_back(i+1);
        int fact=1;
        for(int i=1;i<n;i++) fact*=i;
        string ans="";
        k--;
        while(true){
            int idx=k/fact;
            ans+=to_string(nums[idx]);
            k%=fact;
            nums.erase(nums.begin()+idx);
            if(nums.empty()) return ans;
            fact/=nums.size();
        }
        return ans;
    }
};