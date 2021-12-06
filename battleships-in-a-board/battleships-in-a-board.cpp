class Solution {
public:
    int countBattleships(vector<vector<char>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='.') continue;
                if(i>0 and grid[i-1][j]=='X') continue;
                if(j>0 and grid[i][j-1]=='X') continue;
                ans++;
            }
        }
        return ans;
    }
};