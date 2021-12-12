class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y){
        //for the step 2, 'E' -> change to revealed blank 'B' and all adjacent are revealed recursively...
        int r=grid.size(),c=grid[0].size();
        if(grid[x][y]=='M'){
            grid[x][y]='X';
            return;
        }
        else{
            //it is 'E' now..count the adjacent mines..
            int mines=0;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 and j==0) continue;
                    int newx=x+i,newy=y+j;
                    if(newx>=0 and newx<r and newy>=0 and newy<c){
                        if(grid[newx][newy]=='M' or grid[newx][newy]=='X'){
                            //'m' -> unrevealed mine, 'x' -> unrevealed mine..
                            mines++;
                        }
                    }
                }
            }
            if(mines){
                //there are mines..
                grid[x][y]=mines+'0';
                return;
            }
            else{
                grid[x][y]='B';
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(i==0 and j==0) continue;
                        int newx=x+i,newy=y+j;
                        if(newx>=0 and newx<r and newy>=0 and newy<c){
                            if(grid[newx][newy]=='E'){
                                //'m' -> unrevealed mine, 'x' -> unrevealed mine..
                                dfs(grid,newx,newy);
                            }
                        }
                    }
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board,click[0],click[1]);
        return board;
    }
};