class Solution {
public:
    bool poss(vector<int>& nums,int cap,int maxDays){
        int days=1,cs=nums[0];
        for(int i=1;i<nums.size();i++){
            cs+=nums[i];
            if(cs>cap){
                cs=nums[i];
                days++;
            }
        }
        return days<=maxDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int st=weights[0],end=0;
        for(int i: weights){
            st=max(st,i);
            end+=i;
        }
        int ans;
        while(st<=end){
            int mid=(st+end)/2;
            if(poss(weights,mid,days)){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};