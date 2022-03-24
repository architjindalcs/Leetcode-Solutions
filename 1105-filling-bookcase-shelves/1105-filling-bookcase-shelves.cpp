class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int w=books[i-1][0],h=books[i-1][1];
            dp[i]=dp[i-1]+h; //placing directly..
            
            int maxH=h;
            for(int j=i-1;j>=1 and w+books[j-1][0]<=shelfWidth;j--){
                w+=books[j-1][0];
                maxH=max(maxH,books[j-1][1]);
                dp[i]=min(dp[i],dp[j-1]+maxH);
            }
        }
        return dp[n];
    }
};