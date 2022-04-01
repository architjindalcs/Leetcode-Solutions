class Solution {
public:
    unordered_map<string,bool> dp;
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        string key=s1+"#"+s2;
        if(dp.count(key)) return dp[key];
        vector<int> f(256,0);
        for(char ch: s1) f[ch]++;
        for(char ch: s2) f[ch]--;
        for(int i: f) if(i) return dp[key]=false;
        /*
            [g]reat   rgea[t]
            cfs-> characters from string.
        */
        int n=s1.size();
        for(int cfs=1;cfs<s1.size();cfs++){
            bool c1=isScramble(s1.substr(0,cfs),s2.substr(0,cfs));
            bool c2=isScramble(s1.substr(cfs),s2.substr(cfs));
            
            if(c1 and c2) return dp[key]=true;
            
            bool c3=isScramble(s1.substr(0,cfs),s2.substr(n-cfs));
            bool c4=isScramble(s1.substr(cfs),s2.substr(0,n-cfs));
            
            if (c3 and c4) return dp[key]=true;
        }
        return dp[key]=false;
    }
};