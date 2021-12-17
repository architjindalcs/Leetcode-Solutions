class Solution {
public:
    void helper(string& s,int& o,int& z){
        for(char ch: s) {
            if(ch=='0') z++;
            else o++;
        }
    }
    int findMaxForm(vector<string>& strs, int zlim, int olim) {
        int n=strs.size(); //kind of 0/1 knapsack problem..
        int dp[n+1][zlim+1][olim+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int o=0,z=0; helper(strs[i-1],o,z);
            for(int zval=0;zval<=zlim;zval++){
                for(int oval=0;oval<=olim;oval++){
                    if(!(z<=zval and o<=oval)){
                        //i can't chose this string as a part of my subset..
                        dp[i][zval][oval]=dp[i-1][zval][oval];
                    }
                    else{
                        dp[i][zval][oval]=max(dp[i-1][zval][oval],1+dp[i-1][zval-z][oval-o]);
                    }
                }
            }
        }
        return dp[n][zlim][olim];
    }
};