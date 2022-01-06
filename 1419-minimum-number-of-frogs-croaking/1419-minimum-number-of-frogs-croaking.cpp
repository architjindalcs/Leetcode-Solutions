class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int dp[5];
        int maxm=0,ongoing=0;
        memset(dp,0,sizeof(dp));
        for(char ch: croakOfFrogs){
            if(ch=='c'){
                ongoing++;
                dp[0]++;
                maxm=max(maxm,ongoing);
            }
            else if(ch=='r'){
                dp[1]++;
                if(dp[1]>dp[0]) return -1;
            }
            else if(ch=='o'){
                dp[2]++;
                if(dp[2]>dp[1]) return -1;
            }
            else if(ch=='a'){
                dp[3]++;
                if(dp[3]>dp[2]) return -1;
            }
            else{
                dp[4]++;
                if(dp[4]>dp[3]) return -1;
                ongoing--;
            }
        }
        int ele=dp[0];
        for(int i=0;i<5;i++){
            if(ele!=dp[i]) return -1;
        }
        return maxm;
    }
};