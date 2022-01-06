class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minm=INT_MAX,sminm=INT_MAX;
        for(int i: nums){
            if(i<=minm){
                minm=i;
            }
            else if(i<=sminm){
                //here we reaches..if i>minm 
                sminm=i;
            }
            else return true;
        }
        return false;
    }
};