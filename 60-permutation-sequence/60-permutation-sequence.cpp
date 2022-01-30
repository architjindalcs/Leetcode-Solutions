class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        string ans="";
        k--;
        int fact=1;
        for(int i=1;i<n;i++) fact*=i;
        
    
        while(true){
            int idx=(k/fact);
            ans+=(to_string(nums[idx]));
            nums.erase(nums.begin()+idx);
            if(nums.empty()) break;
            k=k%fact;
            fact/=(nums.size());
        }
        return ans;
    }
};