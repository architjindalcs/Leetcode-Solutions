class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        long long maxPro[r][c];
        long long minPro[r][c];
        maxPro[0][0]=grid[0][0];
        minPro[0][0]=grid[0][0];
        for(int i=1;i<r;i++){
            maxPro[i][0]=minPro[i][0]=(grid[i][0]*minPro[i-1][0]);
        }
        for(int j=1;j<c;j++){
            minPro[0][j]=maxPro[0][j]=(grid[0][j]*minPro[0][j-1]);
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                long long cbminm=grid[i][j]*min(minPro[i-1][j],minPro[i][j-1]);
                long long cbmaxm=(grid[i][j]*max(maxPro[i-1][j],maxPro[i][j-1]));
                maxPro[i][j]=max(cbminm,cbmaxm);
                minPro[i][j]=min(cbminm,cbmaxm);
            }
        }
        return maxPro[r-1][c-1]<0? -1: maxPro[r-1][c-1]%1000000007;
    }
};