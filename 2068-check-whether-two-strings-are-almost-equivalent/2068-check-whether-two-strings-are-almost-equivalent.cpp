class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int f[26];
        memset(f,0,sizeof(f));
        for(char ch: word1) f[ch-'a']++;
        for(char ch: word2) f[ch-'a']--;
        for(int i=0;i<26;i++){
            if(!(f[i]>=-3 and f[i]<=3)) return false;
        }
        return true;
    }
};