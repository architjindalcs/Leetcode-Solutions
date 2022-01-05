class Solution {
public:
    string getHint(string secret, string guess) {
        int f[10];
        memset(f,0,sizeof(f));
        for(char ch: secret) f[ch-'0']++;
        int equal=0,cbs=0;
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]){
                int c=secret[i]-'0';
                f[c]--;
                equal++;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i]!=guess[i]) {
                int c=guess[i]-'0';
                if(f[c]){
                    cbs++;
                    f[c]--;
                }
            }
        }
        return to_string(equal)+"A"+to_string(cbs)+"B";
    }
};