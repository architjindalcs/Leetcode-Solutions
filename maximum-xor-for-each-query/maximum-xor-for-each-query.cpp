class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mbit) {
        int xval=0;
        for(int i: nums) xval=xval xor i;
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            //find k such that xval xor k is maximized and k<pow(2,mbit);
            //k<pow(2,3) -> k<8 -> k<=7 (111) -> atmost mbit set bit could be there..
            int pb=0;
            for(int bitNo=mbit-1;bitNo>=0;bitNo--){
                if((xval&(1<<bitNo))==0){
                    //if this bit is not set, in the xval, then we gonna set this bit in k
                    pb=pb*2+1;
                }
                else pb=pb*2;
            }
            ans.push_back(pb);
            xval=xval xor nums[i];
        }
        return ans;
    }
};