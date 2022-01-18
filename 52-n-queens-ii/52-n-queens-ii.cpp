class Solution {
public:
    int ans=0;
     void helper(vector<vector<int>>& grid,int row,int cm,int ldm,int rdm){
        if(row==(grid.size())){
            ans++;
            return;
        }
        for(int col=0;col<grid.size();col++){
            if(cm&(1<<col)) continue;  //already occupied column previously..
            bool c1=(ldm&(1<<(row-col+grid.size()-1)));
            bool c2=(rdm&(1<<(row+col)));
            if(!c1 and !c2){
                grid[row][col]=1;
                helper(grid,row+1,cm | (1<<col),(ldm|(1<<(row-col+grid.size()-1))),rdm|(1<<(row+col)));
                grid[row][col]=0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        helper(grid,0,0,0,0);
        return ans;
    }
};