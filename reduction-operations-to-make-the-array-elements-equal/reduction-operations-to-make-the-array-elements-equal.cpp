class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        int ans=0,prev=0,cnt=0;
        while(i>=0){
            int k=nums[i];
            while(i>=0 and nums[i]==k){
                cnt++;
                i--;
            }
        //    cout<<"cnt: "<<cnt<<endl;
            if(i!=-1)
            ans+=cnt;
        }
        return ans;
    }
};