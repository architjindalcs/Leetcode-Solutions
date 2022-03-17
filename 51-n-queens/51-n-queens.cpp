class Solution {
public:
    vector<vector<string>> ans;
    vector<string> sfy(vector<vector<int>>& grid){
        vector<string> ans;
        for(auto& v: grid){
            string s="";
            for(int i: v) if(i) s+="Q"; else s+=".";
            ans.push_back(s);
        }
        return ans;
    }
    
    void helper(vector<vector<int>>& grid,int row,int cm,int ldm,int rdm){
        if(row==grid.size()){
            ans.push_back(sfy(grid));
            return;
        }
        for(int col=0;col<grid[0].size();col++){
            if(cm&(1<<col)) continue;
            bool c1=(rdm&(1<<(row+col)));
            bool c2=(ldm&(1<<(row-col+grid.size()-1)));
            if(!c1 and !c2){
                grid[row][col]=1;
                helper(grid,row+1,cm|(1<<col),ldm|(1<<(row-col+grid.size()-1)), rdm | (1<<(row+col)));
                grid[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        helper(grid,0,0,0,0);
        return ans;
    }
};