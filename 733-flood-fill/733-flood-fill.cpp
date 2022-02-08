class Solution {
public:
    void helper(vector<vector<int>>& grid,int x,int y,int oc,int nc){
        int r=grid.size(),c=grid[0].size();
        grid[x][y]=nc;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and grid[newx][newy]==oc){
                helper(grid,newx,newy,oc,nc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oc=image[sr][sc];
        if(oc==newColor) return image;
        helper(image,sr,sc,oc,newColor);
        return image;
    }
};