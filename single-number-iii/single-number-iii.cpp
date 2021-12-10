class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int xval=0;
        for(int i: nums) xval=xval xor i;
        int bitp=0;
        int temp=xval;
        while(temp){
            if(temp&1)
                break;
            temp>>=1;
            bitp++;
        }
        int ele1=0,ele2=0;
        for(int i: nums){
            if(i&(1<<bitp)) ele1=ele1 xor i;
        }
        return {ele1,xval xor ele1};
    }
};