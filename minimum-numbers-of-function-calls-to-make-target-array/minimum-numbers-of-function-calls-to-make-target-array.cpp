class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        while(true){
            int cntz=0;
            bool even=true;
            for(int& i: nums){
                if(i){
                    if(i&1){
                        i--;
                        ans++;
                        even=false;
                    }
                }
                else cntz++;
            }
            if(cntz==nums.size()) return ans;
            if(even){
                ans++;
                for(int& i: nums) i/=2;
            }
        }
        return ans;
    }
};