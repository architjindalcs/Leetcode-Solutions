class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        int row[10];
        int col[10]; 
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        int sg[3][3];
        memset(sg,0,sizeof(sg));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]=='.') continue;
                int num=grid[i][j]-'0';
                if(row[i]&(1<<num)) return false;  //already used..
                if(col[j]&(1<<num)) return false;
                
                if(sg[i/3][j/3]&(1<<num)) return false;
                
                row[i]=row[i] | (1<<num);
                col[j]=col[j] | (1<<num);
                sg[i/3][j/3]= sg[i/3][j/3] | (1<<num);
            }
        }
        return true;
    }
};