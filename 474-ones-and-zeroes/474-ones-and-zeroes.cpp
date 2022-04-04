class Solution {
public:
    void helper(string& s,int& ones,int& zeros){
        for(char ch:  s){
            if(ch=='0') zeros++;
            else ones++;
        }
    }
    int findMaxForm(vector<string>& strs, int maxZ, int maxO){
        int n=strs.size();
        int dp[n+1][maxZ+1][maxO+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            int oc=0,zc=0;
            helper(strs[i-1],oc,zc);
            
            for(int z=0;z<=maxZ;z++){
                for(int o=0;o<=maxO;o++){
                    if(!(z>=zc and o>=oc)){
                        dp[i][z][o]=dp[i-1][z][o];
                    }
                    else{
                        dp[i][z][o]=max(dp[i-1][z][o],1+dp[i-1][z-zc][o-oc]);
                    }
                }
            }
        }
        return dp[n][maxZ][maxO];
    }
};