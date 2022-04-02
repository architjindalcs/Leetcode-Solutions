class Solution {
public:
    void gameOfLife(vector<vector<int>>& grid) {
        /*
           grid[i][j] & (1<<0) -> original state
           grid[i][j] & (1<<1) -> new state
        */
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int cntAlive=0,cntDead=0;
                for(int dx=-1;dx<=1;dx++){
                    for(int dy=-1;dy<=1;dy++){
                        if(!dx and !dy) continue;
                        int newx=i+dx,newy=j+dy;
                        if(newx>=0 and newx<r and newy>=0 and newy<c){
                            int oldState=(grid[newx][newy] & 1)>0;
                            if(oldState==0) cntDead++;
                            else cntAlive++;
                        }
                    }
                }
                int cstate=(grid[i][j]&1) > 0;
                if(cstate and cntAlive<2){
                    //1st bit is already unset no issues, already dead in future
                }
                else if(cstate and (cntAlive==2 or cntAlive==3)){
                    grid[i][j]=grid[i][j] | (1<<1);
                }
                
                if(!cstate and cntAlive==3){
                    grid[i][j]=grid[i][j] | (1<<1);
                }
            }
        }
        for(auto& v: grid){
            for(int& i: v) i/=2;
        }    
    }
};