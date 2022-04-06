class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<=31;i++)
            ans+=(((c&(1<<i)) > 0)? (!(((a&(1<<i)) > 0)==1 or ((b&(1<<i)) > 0)==1)) : ((((a&(1<<i)) > 0)? 1 : 0) + (((b&(1<<i)) > 0)? 1: 0)) );
        return ans;
    }
};