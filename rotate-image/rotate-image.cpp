class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) swap(grid[i][j],grid[j][i]);
        }
        int c1=0,c2=grid[0].size()-1;
        while(c1<c2){
            for(int i=0;i<grid.size();i++) 
                swap(grid[i][c1],grid[i][c2]);
            c1++;
            c2--;
        }
    }
};