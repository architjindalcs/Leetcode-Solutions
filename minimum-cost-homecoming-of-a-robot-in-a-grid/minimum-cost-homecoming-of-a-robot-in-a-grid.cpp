class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;
        for(int i=homePos[0];i!=startPos[0];i=(homePos[0]>startPos[0]? i-1: i+1))
            ans+=rowCosts[i];
        for(int i=homePos[1];i!=startPos[1];i=(homePos[1]>startPos[1]? i-1: i+1))
            ans+=colCosts[i];
        return ans;
    }
};