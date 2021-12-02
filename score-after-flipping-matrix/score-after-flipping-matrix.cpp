class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        /*
            0 1 1 0
            1 1 1 1
            1 0 0 1
        */
        int r=grid.size(),c=grid[0].size();
        bool flip[r];
        memset(flip,false,sizeof(flip));
        int ans=r*(1<<(c-1));
        for(int i=0;i<r;i++){
            if(grid[i][0]==0) flip[i]=true;
        }
        for(int j=1;j<c;j++){
            int cz=0,co=0;
            for(int i=0;i<r;i++){
                int val=flip[i]? 1-grid[i][j] : grid[i][j];
                if(val) co++; 
                else cz++;
            }
            int maxm=max(cz,co);
            ans+=(maxm*(1<<(c-1-j)));
        }
        return ans;
    }
};