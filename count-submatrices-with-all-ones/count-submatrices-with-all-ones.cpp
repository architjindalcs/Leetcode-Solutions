class Solution {
public:
    int numSubmat(vector<vector<int>>& grid) {
       int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            int cs=0;
            for(int j=c-1;j>=0;j--){
                if(grid[i][j]==0) cs=0;
                else cs++;
                grid[i][j]=cs;
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int minm=grid[i][j];
                ans+=minm;
                int row=i+1;
                while(row<r){
                    minm=min(minm,grid[row][j]);
                    ans+=minm;
                    row++;
                }
            }
        }
        return ans;
    }
};