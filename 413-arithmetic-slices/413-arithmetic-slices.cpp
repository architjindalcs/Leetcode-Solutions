class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i=1;
        int ans=0;
        while(i<nums.size()){
            int d=nums[i]-nums[i-1];
            int cnt=0;
            while(i<nums.size() and nums[i]-nums[i-1]==d){
                cnt++;
                i++;
            }
            cnt++;
            //cout<<"cnt: "<<cnt<<endl;
            /*
                1,2,3,4,6
                  i i i i
            */
            ans+=((cnt*(cnt+1))/2)-(2*cnt-1);
        }
        return ans;
    }
};