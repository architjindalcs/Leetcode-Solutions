class Solution {
public:
    int minSwaps(string s) {
        int cnt1=0,cnt0=0;
        for(char ch: s){
            if(ch=='0')
                cnt0++;
            else cnt1++;
        }
        if(!(abs(cnt1-cnt0)<=1)) return -1; 
        //1010101
        int swp1=0,swp0=0;
        
        int rc1=1,rc0=0;
        
        for(char ch: s){
            int c=ch-'0';
            if(c!=rc1) swp1++;
            if(c!=rc0) swp0++;
            rc0=1-rc0; rc1=1-rc1;
        }
        if(cnt1==cnt0)
        return min(swp1/2,swp0/2);
        if(cnt0>cnt1) return swp0/2;
        return swp1/2;
    }
};