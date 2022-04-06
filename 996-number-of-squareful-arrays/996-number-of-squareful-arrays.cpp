class Solution {
public:
    int cnt=0;
    bool sqr(int num){
        int root=sqrt(num);
        return root*root==num;
    }
    void helper(vector<int>& nums,int idx){
        if(idx==nums.size()){
            cnt++;
            return;
        }
        unordered_set<int> st;
        for(int i=idx;i<nums.size();i++){
            if(st.count(nums[i])) continue;
            swap(nums[i],nums[idx]);
            st.insert(nums[idx]);
            if(idx==0 or (idx and sqr(nums[idx]+nums[idx-1]))){
                helper(nums,idx+1);
            }
            swap(nums[i],nums[idx]);
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        helper(nums,0);
        return cnt;
    }
};