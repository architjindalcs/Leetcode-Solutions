class Solution {
public:
    bool canConstruct(string s, int k) {
        int f[26];
        memset(f,0,sizeof(f));
        for(char ch: s) f[ch-'a']++;
        int oddf=0;
        for(int i=0;i<26;i++){
            if(f[i]&1) oddf++;
        }
        return oddf<=k and k<=s.size();
    }
};