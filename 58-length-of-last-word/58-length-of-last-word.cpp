class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=0;
        int len=0,clen=0;
        while(i<=s.size()){
            if(i==s.size() or s[i]==' '){
                if(clen)
                    len=clen;
                clen=0;
            }
            else clen++;
            i++;
        }
        return len;
    }
};