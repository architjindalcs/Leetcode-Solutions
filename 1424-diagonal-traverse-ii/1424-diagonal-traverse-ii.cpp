class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& grid) {
        vector<int> ans;
        int maxm=0;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxm=max(maxm,(int)grid[i].size());
                m[i+j].push_back(grid[i][j]);
            }
        }
        for(int i=0;i<grid.size();i++){
            int sum=i;
            for(int j=m[sum].size()-1;j>=0;j--) ans.push_back(m[sum][j]);
        }
        for(int i=1;i<=maxm;i++){
            int sum=i+grid.size()-1;
            for(int j=m[sum].size()-1;j>=0;j--){
                ans.push_back(m[sum][j]);
            }
        }
        return ans;
    }
};