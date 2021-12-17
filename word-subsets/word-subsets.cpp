class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(string& s: words2){
            int f[26];
            memset(f,0,sizeof(f));
            for(char ch: s) f[ch-'a']++;
            for(int i=0;i<26;i++) cnt[i]=max(cnt[i],f[i]);
        }
      //  vector<string> ans;
        for(string& s: words1){
            int f[26];
            memset(f,0,sizeof(f));
            for(char ch: s) f[ch-'a']++;
            bool ff=true;
            for(int i=0;i<26;i++){
                if(f[i]<cnt[i]){
                    ff=false;
                    break;
                }
            }
            if(ff) ans.push_back(s);
        }
        return ans;
    }
};