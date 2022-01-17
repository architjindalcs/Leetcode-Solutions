class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        long long absSum=0;
        int cntgt0=0;
        int minm=INT_MAX;
        int cntNeg=0;
        for(vector<int>& v: grid){
            for(int i: v) {
                absSum+=abs(i);
                cntgt0+=(i>=0);
                cntNeg+=(i<0);
                minm=min(minm,(int)abs(i));
            }
        }
        if(cntNeg==0 or cntNeg%2==0) return absSum; //no issues then..
        //now cntNeg agr odd h toh..
        //cout<<"absSum: "<<absSum<<endl;
        return absSum-2*minm;
        
    }
};