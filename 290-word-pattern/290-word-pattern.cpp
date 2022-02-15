class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int idx=0;
        int i=0; string cs="";
        unordered_map<string,char> mp;
        unordered_map<char,string> rmp;
        while(i<=s.size()){
            if(i==s.size() or s[i]==' '){
                if(idx==pattern.size()) return false;
                char ch=pattern[idx++];
                if(!mp.count(cs) and !rmp.count(ch)){
                    mp[cs]=ch;
                    rmp[ch]=cs;
                }
                else if(!mp.count(cs) or !rmp.count(ch)) return false;
                else if(!(mp[cs]==ch and rmp[ch]==cs)){
                    return false;
                }
                cs="";
                i++;
            }
            else cs+=s[i++];
        }
        return i==s.size()+1 and pattern.size()==idx;
    }
};