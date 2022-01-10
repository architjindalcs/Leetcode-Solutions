class Solution {
public:
    bool checkValid(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            unordered_set<int> st;
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]>grid.size()) return false;
                else st.insert(grid[i][j]);
            }
            if(st.size()!=grid.size()) return false;
            st.clear();
            
            for(int j=0;j<grid[i].size();j++) {
                if(grid[j][i]>grid.size()) return false;
                else st.insert(grid[j][i]);
            }if(st.size()!=grid.size()) return false;
        }     
        return true;
    }
};