class Solution {
public:
    unordered_map<string,bool> dp;
    bool isScramble(string s1, string s2) {
        string key=s1+"#"+s2;
        int f1[26],f2[26];
        if(s1==s2) return true;  //yes they are scrambled strings..
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(char ch: s1) f1[ch-'a']++;
        for(char ch: s2) f2[ch-'a']++;
        
        for(int i=0;i<26;i++) {
       //     temp+=(to_string(f1[i])+",");
            if(f1[i]!=f2[i]) return dp[key]=false;
        }
        
        if(dp.count(key)) return dp[key];
        
        int n=s1.size();
        for(int i=0;i<s1.size()-1;i++){
            if(isScramble(s1.substr(0,i+1),s2.substr(0,i+1)) and isScramble(s1.substr(i+1),s2.substr(i+1)))
                return dp[key]=true;
            int leftS1=(i+1),rightS1=s1.size()-(leftS1);
            if(isScramble(s1.substr(0,leftS1),s2.substr(n-leftS1,leftS1)) and               
               isScramble(s1.substr(n-rightS1,rightS1),s2.substr(0,rightS1))) 
                return dp[key]=true;
        }
        return dp[key]=false;
    }
};