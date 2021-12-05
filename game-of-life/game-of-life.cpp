class Solution {
public:
    void gameOfLife(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        //xy -> 2bits (x->updated state, y-> curr state)
        
        int row[]={0,0,1,-1,1,1,-1,-1};
        int col[]={1,-1,0,0,1,-1,1,-1};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int alive=0,dead=0;
                for(int k=0;k<8;k++){
                    int newx=i+row[k],newy=j+col[k];
                    if(newx>=0 and newx<r and newy>=0 and newy<c){
                        if(grid[newx][newy]&1) alive++;
                        else dead++;
                    }
                }
                if(grid[i][j]&1){
                    //it is currently alive
                    if(alive<2) {
                        //no update needed as 1st bit is already 0;
                    }
                    else if(alive==2 or alive==3){
                        grid[i][j]=(grid[i][j] | (1<<1)); //setting the 1st bit..
                    }
                    else if(alive>3)
                    {
                        //no update needed as 1st bit is already 0;
                    }
                }
                else{
                    //currently in dead state
                    if(alive==3)
                        grid[i][j]=grid[i][j] | (1<<1);
                }
            }
        }
        for(vector<int>& v: grid){
            for(int& i: v) i>>=1;
        }
    //    return grid;
    }
};