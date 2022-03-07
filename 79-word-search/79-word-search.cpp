class Solution {
public:
    bool helper(vector<vector<char>>& board,int x,int y,string& word,int idx){
        if(idx==word.size()) return true;
        int row[]={0,0,1,-1}; 
        int col[]={1,-1,0,0};
        char ch=board[x][y];
        board[x][y]='$'; //i used it for current traversal..
        for(int k=0;k<4;k++){
            int newx=x+row[k],newy=y+col[k];
            if(newx>=0 and newx<board.size() and newy>=0 and newy<board[0].size() 
              and board[newx][newy]==word[idx]){
                if(helper(board,newx,newy,word,idx+1))
                    return true;
            }
        }
        board[x][y]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(),c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    if(helper(board,i,j,word,1)) return true;
                }
            }
        }
        return false;
    }
    
};