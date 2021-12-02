class Solution {
public:
    int countSquares(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(grid[i][j]){
                    grid[i][j]=1+min(grid[i-1][j-1],min(grid[i-1][j],grid[i][j-1]));
                }
            }
        }
        int ans=0;
        for(vector<int>& v: grid){
            for(int i: v) ans+=i;
        }
        return ans;
    }
};