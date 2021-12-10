class Solution {
public:
    bool poss(vector<vector<int>>& grid,vector<vector<bool>>& vis,int x,int y,int mDiff){
        int r=grid.size(),c=grid[0].size();
        if(x==r-1 and y==c-1) return true;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        vis[x][y]=true;
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<r and newy>=0 and newy<c and !vis[newx][newy] and abs(grid[newx][newy]-grid[x][y])<=mDiff){
                if(poss(grid,vis,newx,newy,mDiff))
                    return true;
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        int s=0,e=1000000;
        int ans;
        int r=grid.size(),c=grid[0].size();
        while(s<=e){
            int mid=(s+e)/2;
            vector<vector<bool>> vis(r,vector<bool>(c,false));
            if(poss(grid,vis,0,0,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};