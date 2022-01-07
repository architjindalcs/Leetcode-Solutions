class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& grid) {
        vector<int> ans;
        int maxm=0;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxm=max(maxm,i+j);
                m[i+j].push_back(grid[i][j]);
            }
        }

        for(int i=0;i<=maxm;i++){
            int sum=i;
            for(int j=m[sum].size()-1;j>=0;j--){
                ans.push_back(m[sum][j]);
            }
        }
        return ans;
    }
};