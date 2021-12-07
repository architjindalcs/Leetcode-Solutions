class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int r=row.size(),c=col.size();
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int minm=min(row[i],col[j]);
                ans[i][j]=minm;
                row[i]-=minm;
                col[j]-=minm;
            }
        }
        return ans;
    }
};