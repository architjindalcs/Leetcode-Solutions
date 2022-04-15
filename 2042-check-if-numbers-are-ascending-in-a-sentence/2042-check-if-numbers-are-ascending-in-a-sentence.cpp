class Solution {
public:
    bool areNumbersAscending(string s) {
        int last=-1;
        int i=0;
        while(i<s.size()){
            if(s[i]>='0' and s[i]<='9'){
                int num=0;
                while(i<s.size() and s[i]>='0' and s[i]<='9'){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                if(num<=last) return false;
                last=num;
            }
            else i++;
        }
        return true;
    }
};