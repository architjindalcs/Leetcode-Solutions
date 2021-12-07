class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i=1;i<r;i++) grid[i][0]+=grid[i-1][0];
        for(int j=1;j<c;j++) grid[0][j]+=grid[0][j-1];
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                grid[i][j]+=(grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int x1=max(0,i-k),x2=min(r-1,i+k);
                int y1=max(0,j-k),y2=min(c-1,j+k);
                ans[i][j]=grid[x2][y2];
                if(x1) ans[i][j]-=grid[x1-1][y2];
                if(y1) ans[i][j]-=grid[x2][y1-1];
                if(x1 and y1) ans[i][j]+=grid[x1-1][y1-1];
            }
        }
        return ans;
    }
};