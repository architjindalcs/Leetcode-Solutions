class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string cs="";
        for(int i=0;i<s.size()/2;i++){
            cs+=s[i];
            int csl=cs.size();
            if(n%csl==0){
                string temp="";
                int times=n/csl;
                while(times--) temp+=cs;
                if(temp==s) return true;
            }
        }
        return false;
    }
};