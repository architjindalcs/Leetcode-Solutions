class Solution {
public:
    bool isValidSerialization(string s) {
        int cap=1;
        s+=",";
        for(int i=0;i<s.size();i++){
            if(s[i]!=',') {
                continue;
            }
            if(s[i-1]=='#'){
                cap--;
                if(cap<0) return false;
            }
            else{
                cap--;
                if(cap<0) return false;
                cap+=2;
            }
        }
        return cap==0;
    }
};