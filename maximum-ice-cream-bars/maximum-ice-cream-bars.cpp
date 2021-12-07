class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        int idx=0;
        while(idx<costs.size() and coins>=costs[idx]){
            coins-=costs[idx++];
        }
        return idx;
    }
};