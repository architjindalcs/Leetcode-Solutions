class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int l=0,r=height.size()-1;
        while(l<r){
            int minm=min(height[l],height[r]);
            ans=max(ans,minm*(r-l));
            if(height[l]<=height[r])
                l++;
            else r--;
        }
        return ans;
    }
};