class Solution {
public:
    int helper(vector<int>& nums1,vector<int>& nums2){
        unordered_map<int,int> m;
        for(int i: nums2) m[i]++;
        int ans=0;
        for(long num: nums1){
            num=num*num;
            for(auto x: m){
                int ele1=x.first;
                int f1=x.second;
                //2,2,2,2,8,8
                if(num%ele1 or m.count(num/ele1)==0) continue;
                int ele2=(num/ele1);
                int f2=m[ele2];
                if(ele1==ele2) ans+=(f1*(f1-1));
                else ans+=(f1*f2);
            }
        }
        return ans/2;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1,nums2)+helper(nums2,nums1);
    }
};