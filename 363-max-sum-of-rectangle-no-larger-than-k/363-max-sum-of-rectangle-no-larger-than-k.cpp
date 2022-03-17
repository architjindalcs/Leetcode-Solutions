class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        for(int col=1;col<c;col++){
            for(int row=0;row<r;row++) grid[row][col]+=grid[row][col-1];
        }
        int maxm=INT_MIN;
        for(int stcol=0;stcol<c;stcol++){
            for(int endcol=stcol;endcol<c;endcol++){
                set<int> st;
                st.insert(0);
                int cs=0;
                for(int i=0;i<r;i++){
                    int ele=grid[i][endcol]-(stcol? grid[i][stcol-1]: 0);
                    cs+=ele;
                        /*
                            cs-x<=k
                            x>=cs-k
                        */
                    auto it=st.lower_bound(cs-k);
                    if(it!=st.end()){
                        maxm=max(maxm,cs-(*it));
                    }
                    st.insert(cs);
                }
            }
        }
        return maxm;
    }
};