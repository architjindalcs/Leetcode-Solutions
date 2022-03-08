class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int st=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[st]){
                ans=max(ans,prices[i]-prices[st]);
            }
            else st=i;
        }
        return ans;
    }
};