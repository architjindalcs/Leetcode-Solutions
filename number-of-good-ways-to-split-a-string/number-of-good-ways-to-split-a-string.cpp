class Solution {
public:
    int numSplits(string s) {
        int ans=0;
        int right[26],left[26];
        memset(right,0,sizeof(right));
        memset(left,0,sizeof(left));
        for(char ch: s) right[ch-'a']++;
        for(int i=0;i<s.size();i++){
            left[s[i]-'a']++;
            right[s[i]-'a']--;
            int cnt1=0,cnt2=0;
            for(int i=0;i<26;i++) {
                cnt1+=(left[i]>0);
                cnt2+=(right[i]>0);
            }
            if(cnt1==cnt2) ans++;
        }
        return ans;
    }
};