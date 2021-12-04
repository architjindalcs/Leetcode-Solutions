class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<vector<int>>& grid,int x,int y,int& xmin,int& ymin,int& xmax,int& ymax){
        int r=grid.size(),c=grid[0].size();
        xmin=min(xmin,x); ymin=min(ymin,y); xmax=max(xmax,x); ymax=max(ymax,y);
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        grid[x][y]=0;
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy])
                helper(grid,newx,newy,xmin,ymin,xmax,ymax);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    int xmin,ymin,xmax,ymax;
                    xmin=xmax=i; ymin=ymax=j;
                    helper(grid,i,j,xmin,ymin,xmax,ymax);
                    ans.push_back({xmin,ymin,xmax,ymax});
                }
            }
        }
        return ans;
    }
};