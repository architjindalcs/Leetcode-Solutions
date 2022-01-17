class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        queue<pair<int,int>> q;
        int r=grid.size(),c=grid[0].size();
        q.push({entrance[0],entrance[1]});
        int level=0;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        grid[entrance[0]][entrance[1]]='+';
        while(q.size()){
            int siz=q.size();
            while(siz--){
                pair<int,int> fr=q.front();
                q.pop();
                int x=fr.first,y=fr.second;
                for(int k=0;k<4;k++){
                    int newx=x+row[k],newy=y+col[k];
                    if(newx>=0 and newx<r and newy>=0 and newy<c){
                        if(grid[newx][newy]!='+' and (newx==0 or newy==0 or newx==r-1 or newy==c-1))
                            return level+1;
                        else if(grid[newx][newy]!='+'){
                            q.push({newx,newy});
                            grid[newx][newy]='+';   
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};