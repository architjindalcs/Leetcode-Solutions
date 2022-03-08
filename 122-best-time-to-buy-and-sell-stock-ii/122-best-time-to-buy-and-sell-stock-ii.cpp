class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,st=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[st]){
                ans+=(prices[i]-prices[st]);
                st=i;
            }
            else st=i;
        }
        return ans;
    }
};