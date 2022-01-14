class Solution {
public:
    bool winnerOfGame(string s) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                char prev=(i? s[i-1]: '9');
                char next=(i<s.size()-1 ? s[i+1] : '9');
                if(prev=='A' and next=='A') a++;
            }
            else{
                char prev=(i? s[i-1]: '9');
                char next=(i<s.size()-1? s[i+1]: '9');
                if(prev=='B' and next=='B') b++;
            }
        }
        return a>b;
    }
};