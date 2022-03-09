class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
      
        int dhPrevDay=0, hPrevDay=-prices[0];
        int dhPPrevDay=0;
        
        for(int i=1;i<n;i++){
            int hCurrDay=max(hPrevDay,-prices[i]+dhPPrevDay);
            int dhCurrDay=max(dhPrevDay,prices[i]+hPrevDay);
            
            dhPPrevDay=dhPrevDay;
            dhPrevDay=dhCurrDay;
            hPrevDay=hCurrDay;
        }
        return dhPrevDay;
    }
};