class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int j=0;j<c;j++){
            for(int i=1;i<r;i++)
                if(grid[i][j]) grid[i][j]+=grid[i-1][j];
        }
        int ans=0;
        for(auto v: grid){
            sort(v.begin(),v.end(),greater<int>());
            for(int i=0;i<v.size();i++){
                ans=max(ans,(i+1)*v[i]);
            }
        }
        return ans;
    }
};