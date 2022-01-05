class Solution {
public:
    int leastBricks(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        unordered_map<int,int> m;
        for(int i=0;i<r;i++){
            if(grid[i].size()!=1)
            m[grid[i][0]]++;
            for(int j=1;j<grid[i].size();j++) {
                grid[i][j]+=grid[i][j-1];
                if(j!=grid[i].size()-1){
                    m[grid[i][j]]++;
                }
            }
        }
        int maxm=0;
        for(auto x: m)
           maxm=max(maxm,x.second);
        return r-maxm;
    }
};