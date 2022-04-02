class Solution {
public:
    bool check(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
                continue;
            }
            /*
                a  b  c  a
                    i  j
            */
            if(check(s,i+1,j) or check(s,i,j-1)) return true;
            return false;
        }
        return true;
    }
};