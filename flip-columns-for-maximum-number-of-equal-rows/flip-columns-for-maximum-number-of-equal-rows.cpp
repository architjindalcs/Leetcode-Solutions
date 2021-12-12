class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        /* 
            0 1 -> 1 1
            1 0    0 0   -> basically 2 rows are there, hence..
        
            001
            110
            001
            
        */
        unordered_map<string,int> m;
        for(vector<int>& v: grid){
            string ori="";
            string flip="";
            for(int i: v) {
                if(i) {
                    ori+="1";
                    flip+="0";
                }
                else{
                    ori+="0";
                    flip+="1";
                }
            }
            m[ori]++;
            m[flip]++;
        }

        int ans=0;
        for(auto x: m) ans=max(ans,x.second);
        return ans;
    }
};