class Solution {
public:
    bool isValidSerialization(string s) {
        int cap=1;
        s+=",";
        for(int i=0;i<s.size();i++){
            if(s[i]!=',') continue;
            if(s[i-1]!='#'){
                cap--;
                if(cap<0) return false;
                //it is not null node, it will consume a void and create two voids (left child) and (right child) 
                cap+=2;  
            }
            if(s[i-1]=='#'){
                cap--;
                if(cap<0) return false;
            }
        }
        return cap==0;
    }
};