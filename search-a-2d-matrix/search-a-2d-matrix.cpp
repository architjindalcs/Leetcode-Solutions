class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int r=grid.size(),c=grid[0].size();
        int st=0,end=r*c-1;
        while(st<=end){
            int mid=(st+end)/2;
            int i=(mid/c),j=(mid%c);
            if(grid[i][j]==target) return true;
            else if(grid[i][j]<target) st++;
            else end--;
        }
        return false;
    }
};