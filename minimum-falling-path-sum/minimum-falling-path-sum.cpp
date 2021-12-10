class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        if(grid.empty()) return 0;
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                int p1=max(0,j-1);
                int p2=j;
                int p3=min((int)grid[0].size()-1,j+1);
                grid[i][j]+=min(grid[i-1][p1],min(grid[i-1][p2],grid[i-1][p3]));
            }
        }
        int minm=INT_MAX;
        for(int i: grid.back()) minm=min(minm,i);
        return minm;
    }
};