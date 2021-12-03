class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0,r=grid.size(),c=grid[0].size();
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int cnt=4;
                    for(int k=0;k<4;k++){
                        int newx=i+row[k],newy=j+col[k];
                        if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]==1){
                            cnt--;
                        }
                    }
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};