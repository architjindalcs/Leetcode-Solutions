class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        for(int i=1;i<=amount;i++) dp[i]=0;
        dp[0]=1;
        for(int c: coins){
            for(int i=c;i<=amount;i++){
                dp[i]+=dp[i-c];
            }
        }
        return  dp[amount];
    }
};