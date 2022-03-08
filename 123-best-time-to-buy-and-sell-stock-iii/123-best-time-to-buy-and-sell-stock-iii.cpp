class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int left[n]; left[0]=0; 
        int st=0;
        for(int i=1;i<n;i++){
            left[i]=left[i-1];
            if(prices[i]>prices[st]) left[i]=max(left[i],prices[i]-prices[st]);
            else st=i;
        }
        
        
        st=n-1;
        int right[n]; right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1];
            if(prices[i]<prices[st]) right[i]=max(right[i],prices[st]-prices[i]);
            else st=i;
        }

        int ans=0;
        for(int i=0;i<prices.size()-1;i++){
            ans=max(ans,left[i]+right[i+1]);
        }
        ans=max(ans,max(right[0],left[n-1]));
        return ans;
    }
};