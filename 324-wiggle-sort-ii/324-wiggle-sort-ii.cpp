class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
   //     int n=nums.size();
        vector<int> temp(n);
        int idx=n-1;
        for(int i=1;i<nums.size();i+=2){
            temp[i]=nums[idx--];
        }
        int st=((n-1)%2==0? n-1: n-2);
        idx=0;
        for(int i=st;i>=0;i-=2){
            temp[i]=nums[idx++];
        }
        nums=temp;
    }
};