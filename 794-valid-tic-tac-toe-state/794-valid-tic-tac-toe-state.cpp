class Solution {
public:
    bool validTicTacToe(vector<string>& grid) {
        int r=grid.size(),c=grid[0].size();
        int cntX=0,cntY=0;
        vector<int> rowX(3,0),colX(3,0); int ldX=0,rdX=0;
        vector<int> rowY(3,0),colY(3,0); int ldY=0,rdY=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='X'){
                    cntX++;
                    rowX[i]++; colX[j]++;
                    ldX+=(i==j);
                    rdX+=(i+j==2);
                }
                else if(grid[i][j]=='O'){
                    cntY++;
                    rowY[i]++; colY[j]++;
                    ldY+=(i==j);
                    rdY+=(i+j==2);
                }
            }
        }
        int winX=(rowX[0]==3)+(rowX[1]==3)+(rowX[2]==3)+(colX[0]==3)+(colX[1]==3)+(colX[2]==3)+(ldX==3)+(rdX==3);
        
        
        int winY=(rowY[0]==3)+(rowY[1]==3)+(rowY[2]==3)+(colY[0]==3)+(colY[1]==3)+(colY[2]==3)+(ldY==3)+(rdY==3);
        

        if(cntX==cntY){
            //last move by Y
            if(!winX and !winY) return true;
            if(winX) return false;
            return true;
        }
        else if(cntX==cntY+1){
            //last move by X
            if(!winX and !winY) return true;
            if(winY) return false;
            return true;
        }
        return false;
    }
};