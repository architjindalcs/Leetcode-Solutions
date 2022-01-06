class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int prev=0,ans=0;
        for(int i: rungs){
            int diff=(i-prev);
            if(diff<=dist) {
                prev=i;
                continue;
            }
            if(diff%dist==0){
                ans+=((diff/dist)-1);
            }
            else ans+=(diff/dist);
            prev=i;
        }
        return ans;
    }
};