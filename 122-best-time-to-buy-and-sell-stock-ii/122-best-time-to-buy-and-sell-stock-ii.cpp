class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int ans=0;
        while(i<prices.size()){
            while(i<prices.size()-1 and prices[i+1]<=prices[i]){
                i++;
            }
            if(i==prices.size()-1) return ans;
            int buy=i++;
            while(i<prices.size() and prices[i]>=prices[i-1]) i++;
            int sell=i-1;;
            ans+=(prices[sell]-prices[buy]);
        }
        return ans;

    }
};