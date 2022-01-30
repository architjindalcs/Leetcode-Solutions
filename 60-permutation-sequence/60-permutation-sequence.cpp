class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        string ans="";
        k--;
        int fact=1;
        for(int i=1;i<n;i++) fact*=i;
        /* 
            1,[2,3,4]   -> 0-5
            2,[1,3,4]   -> 6-11
            3,[1,2,4]   -> 12-17     fact=6   
            4,[1,2,3]   -> 18-23
        
                //3,4,1,2
        
            1,[2,4]    -> 0-1
            2,[1,4]    -> 2-3
            4,[1,2]    -> 4-5            4/2 =2   k=0
            
            [1,2]  -> k=0  -> 1,2
            
        */
    
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