class Solution {
public:
    vector<vector<char>> ans;
    bool solve(vector<vector<int>>& grid,int row,int col, vector<int>& rmask, vector<int>& cmask,   vector<vector<int>>& sgmask){
        if(row==9){
            return true;
        }
        if(col==9) return solve(grid,row+1,0,rmask,cmask,sgmask);
        
        if(grid[row][col]) return solve(grid,row,col+1,rmask,cmask,sgmask);
        
        for(int num=1;num<=9;num++){
            bool c1=cmask[col] & (1<<num);
            bool c2=rmask[row] & (1<<num);
            bool c3=(sgmask[row/3][col/3]&(1<<num));
            if(!c1 and !c2 and !c3){
                grid[row][col]=num;
                cmask[col]=cmask[col] ^ (1<<num);
                rmask[row]=rmask[row] ^ (1<<num);
                sgmask[row/3][col/3]=sgmask[row/3][col/3] ^ (1<<num);
                
                bool ans=solve(grid,row,col+1,rmask,cmask,sgmask);
                if(ans) return true;
                
                cmask[col]=cmask[col] ^ (1<<num);
                rmask[row]=rmask[row] ^ (1<<num);
                sgmask[row/3][col/3]=sgmask[row/3][col/3] ^ (1<<num);
                grid[row][col]=0;
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> grid;
        vector<int> rmask(9,0); vector<int> cmask(9,0);
        vector<vector<int>> sgmask=vector<vector<int>> (3,vector<int> (3,0));
        for(int row=0;row<9;row++){
            vector<int> temp;
            for(int col=0;col<9;col++) {
                char ch=board[row][col];
                int num=ch-'0';
                if(ch!='.') {
                    cmask[col]=cmask[col] ^ (1<<num);
                    rmask[row]=rmask[row] ^ (1<<num);
                    sgmask[row/3][col/3]=sgmask[row/3][col/3] ^ (1<<num);
                    temp.push_back(ch-'0');
                }
                else temp.push_back(0);
            }
            grid.push_back(temp);
        }


        
        solve(grid,0,0,rmask,cmask,sgmask);
       for(int i=0;i<grid.size();i++){
            vector<char> v;
            for(int j=0;j<grid[0].size();j++){
                char ch=grid[i][j]+'0';
                board[i][j]=ch;
            }
        }
      //  board=ans;
    }   
};
