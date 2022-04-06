class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        int r=rows, c=cols;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int dist=abs(rCenter-i)+abs(cCenter-j);
                ans.push_back({i,j,dist});
            }
        }
        sort(ans.begin(),ans.end(),[&](vector<int>& v1,vector<int>& v2){
           return v1.back()<v2.back(); 
        });
        for(vector<int>& v: ans) v.pop_back();
        return ans;
    }
};