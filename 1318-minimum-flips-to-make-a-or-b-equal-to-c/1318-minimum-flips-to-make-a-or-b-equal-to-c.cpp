class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        // 100
        // 010
        // 111
        for(int i=0;i<=31;i++){
            int abit=(a&(1<<i)) > 0;
            int bbit=(b&(1<<i)) > 0;
            int cbit=(c&(1<<i)) > 0;
            if(cbit==1){
                ans+=(!(abit==1 or bbit==1));
            }
            else {
                ans+=((abit? 1 : 0) + (bbit? 1: 0));
            }
        }
        return ans;
    }
};