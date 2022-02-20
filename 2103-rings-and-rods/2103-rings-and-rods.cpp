class Solution {
public:
    int countPoints(string rings) {
        int dp[10][3];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<rings.size();i+=2){
            int ringNo=rings[i]-'0';
            if(rings[i-1]=='R') dp[ringNo][0]++;
            else if(rings[i-1]=='G') dp[ringNo][1]++;
            else dp[ringNo][2]++;
        }
        int ans=0;
        for(int i=0;i<10;i++){
            if(dp[i][0] and dp[i][1] and dp[i][2])
                ans++;
        }
        return ans;
    }
};