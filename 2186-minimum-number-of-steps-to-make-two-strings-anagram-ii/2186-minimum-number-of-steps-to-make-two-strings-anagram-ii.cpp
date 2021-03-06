class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> f1(26,0),f2(26,0);
        for(char& ch: s) f1[ch-'a']++;
        for(char& ch: t) f2[ch-'a']++;
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=(abs(f1[i]-f2[i]));
        }
        return ans;
    }
};