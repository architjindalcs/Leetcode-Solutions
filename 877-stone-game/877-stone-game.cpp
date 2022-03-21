class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sumEven=0,sumOdd=0;
        for(int i=0;i<piles.size();i++){
            if(i%2==0) sumEven+=piles[i];
            else sumOdd+=piles[i];
        }
        return sumEven!=sumOdd;
    }
};