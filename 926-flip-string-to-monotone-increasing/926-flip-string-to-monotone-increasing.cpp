class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flipcnt=0,onecnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(onecnt==0) continue;
                else flipcnt++;
            }
            else{
                onecnt++;
            }
            if(flipcnt>onecnt)
                flipcnt=onecnt;
        }
        return flipcnt;
    }
};