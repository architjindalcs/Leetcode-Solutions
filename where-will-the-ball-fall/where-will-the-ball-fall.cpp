class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<int> ans;
        for(int j=0;j<c;j++){
            int x=0,y=j;
            while(x<r){
                if(grid[x][y]==1){
                    // \-> ye wala case..
                    if(y==c-1 or grid[x][y+1]==-1) break; 
                    else y++;
                }
                else{
                    //  / -> ye wala case..
                    if(y==0 or grid[x][y-1]==1) break;
                    else y--;
                }
                x++;
            }
            ans.push_back((x==r? y: -1));
        }
        return ans;
    }
};