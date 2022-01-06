class Solution {
public:
    bool check(char ch){
        return (ch>='a' and ch<='z') or (ch>='A' and ch<='Z') or (ch>='0' and ch<='9');
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(!check(s[i])) i++;
            if(!check(s[j])) j--;
            if(check(s[i]) and check(s[j])){
                char ch1=tolower(s[i]);
                char ch2=tolower(s[j]);
                if(ch1!=ch2)
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
};