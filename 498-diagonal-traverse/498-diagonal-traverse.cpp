class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& grid) {
        int x=0,y=0,r=grid.size(),c=grid[0].size();
        vector<int> ans(r*c);
        for(int i=0;i<ans.size();i++){
            ans[i]=grid[x][y];
            if((x+y)%2==0){
                //I need to go up...
                if(y==c-1){
                   x++; 
                }
                else if(x==0){
                    y++;
                }
                else{
                     x-- ; y++;
                }
               
            }
            else{
                if(x==r-1){
                    y++;
                }
                else if(y==0){
                    x++;
                }
                else{
                    x++;
                    y--;
                }
            }
        }
        return ans;
    }
};