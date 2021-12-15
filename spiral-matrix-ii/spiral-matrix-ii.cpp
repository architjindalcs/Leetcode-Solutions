class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int strow=0,endrow=n-1,stcol=0,endcol=n-1;
        int st=1;
        vector<vector<int>> ans(n,vector<int>(n));
        while(strow<=endrow and stcol<=endcol){
            for(int j=stcol;j<=endcol;j++) ans[strow][j]=st++;
            strow++;
            for(int i=strow;i<=endrow;i++) ans[i][endcol]=st++;
            endcol--;
            if(strow<=endrow){
                for(int i=endcol;i>=stcol;i--) ans[endrow][i]=st++;
                endrow--;
            }
            if(stcol<=endcol){
                for(int i=endrow;i>=strow;i--) ans[i][stcol]=st++;
                stcol++;
            }
        }
        return ans;
    }
};