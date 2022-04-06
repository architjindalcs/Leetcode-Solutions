class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int grid[n][n];
        memset(grid,0,sizeof(grid));
        for(vector<int>& d: dig){
            grid[d[0]][d[1]]=1;  //ye have removed mud from here..
        }
        int r=n,c=n;
        for(int i=1;i<r;i++) grid[i][0]+=grid[i-1][0];
        for(int j=1;j<c;j++) grid[0][j]+=grid[0][j-1];
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j+=1){
                grid[i][j]+=(grid[i-1][j]+grid[i][j-1]);
                grid[i][j]-=grid[i-1][j-1];
            }
        }
        int ans=0;
        for(vector<int>& art: artifacts){
            int r1=art[0],c1=art[1],r2=art[2],c2=art[3];
            int sumShouldBe=(r2-r1+1)*(c2-c1+1);
            int sum=grid[r2][c2];
            if(r1>0) sum-=grid[r1-1][c2];
            if(c1>0) sum-=grid[r2][c1-1];
            if(r1 and c1) sum+=grid[r1-1][c1-1];
            ans+=(sum==sumShouldBe);
        }
        return ans;
    }
};