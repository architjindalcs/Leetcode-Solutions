class Solution {
public:
    int maxCoins(vector<int>& piles) {
        /*
           [1,2] 2,5,7,8
        */
        sort(piles.begin(),piles.end());
        int ans=0,n=piles.size();
        for(int i=n-2;i>=(n/3);i-=2) ans+=piles[i];
        return ans;
    }
};