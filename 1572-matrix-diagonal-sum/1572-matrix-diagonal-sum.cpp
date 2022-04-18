class Solution {
public:
    int diagonalSum(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==j)  ans+=grid[i][j];
                if(i+j==grid.size()-1) ans+=(grid[i][j]);
            }
        }
        if(r&1) return ans-grid[r/2][c/2];
        return ans;
    }
};