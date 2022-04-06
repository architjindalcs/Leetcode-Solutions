class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt=0;
        char ch1='$',ch2='$',ch3='$',ch4='$';
       // if(s==goal) return true;
        if(s.size()!=goal.size()) return false;
        if(s==goal){
            int f[26];
            memset(f,0,sizeof(f));
            for(char ch: s) f[ch-'a']++;
            bool ef=false;
            for(int i=0;i<26;i++){
                if(f[i] and f[i]>=2) return true;
            }
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                cnt++;
                if(ch1=='$'){
                    ch1=s[i],ch2=goal[i];
                }
                else if(ch3=='$'){
                    ch3=s[i], ch4=goal[i];
                }
            }
            if(cnt>2) return false;
        }
        return (cnt==2 and  ch1==ch4 and ch2==ch3);
    }
};