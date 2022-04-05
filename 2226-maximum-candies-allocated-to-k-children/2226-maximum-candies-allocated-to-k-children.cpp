class Solution {
public:
    bool poss(vector<int>& nums,int mid,int k){
        // cout<<"mid: "<<mid<<endl;
        long tpiles=0;
        for(int can: nums){
            tpiles+=((can/mid));
        }
        // cout<<"tpiles: "<<tpiles<<endl;
        return tpiles>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long st=1,sum=0;
        for(int i: candies) sum+=i;
        long end=sum/k;
        if(sum<k) return 0;
        int ans;
        while(st<=end){
            int mid=(st+end)/2;
            if(poss(candies,mid,k)){
                ans=mid;
                st=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
};