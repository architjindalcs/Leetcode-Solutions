class Solution {
public:
    int minSteps(string s, string t) {
        int f1[26],f2[26];
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(char ch: s) f1[ch-'a']++;
        for(char ch: t) f2[ch-'a']++;
        int ans=0;
        for(int i=0;i<26;i++){
            if(f2[i]>f1[i]){
                ans+=(f2[i]-f1[i]);
            }
        }
        return ans;
    }
};