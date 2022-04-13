class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int strow=0,endrow=n-1;
        int stcol=0,endcol=n-1;
        int num=1;
        vector<vector<int>> grid(n,vector<int>(n,0));
        while(strow<=endrow and stcol<=endcol){
            for(int j=stcol;j<=endcol;j++){
                grid[strow][j]=num++;
            }     
            strow++;
            for(int i=strow;i<=endrow;i++) {
                grid[i][endcol]=num++;
            }
            endcol--;
            if(strow<=endrow){
                for(int i=endcol;i>=stcol;i--) grid[endrow][i]=num++;
                endrow--;
            }
            if(stcol<=endcol){
                for(int i=endrow;i>=strow;i--) grid[i][stcol]=num++;
                stcol++;
            }
        }
        return grid;
    }
};