class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int row[r],col[c];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                row[i]=max(row[i],grid[i][j]);
                col[j]=max(col[j],grid[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++) ans+=(max(grid[i][j],min(row[i],col[j]))-grid[i][j]);
        return ans;
    }
};