class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        long dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<shifts.size();i++){
            int st=0,end=i;
            dp[st]+=shifts[i];
            dp[end+1]-=shifts[i];
        }
        for(int i=1;i<=n;i++) dp[i]+=dp[i-1];
        for(int i=0;i<n;i++){
            long shift=dp[i];

            long ch=s[i]-'a';
            ch=(ch+shift%26)%26;
            s[i]=(char) (ch+'a');
        }
        return s;
    }
};