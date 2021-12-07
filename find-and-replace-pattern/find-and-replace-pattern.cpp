class Solution {
public:
    bool match(string s1,string s2){
        int rmp[256];
        int mp[256];
        memset(mp,-1,sizeof(mp));
        memset(rmp,-1,sizeof(rmp));
        for(int i=0;i<s1.size();i++){
            int ch1=s1[i],ch2=s2[i];
            if(mp[ch1]==-1 and rmp[ch2]==-1){
                mp[ch1]=ch2;
                rmp[ch2]=ch1;
            }
            else if(mp[ch1]==-1 or rmp[ch2]==-1) return false;
            else{
                if(!(mp[ch1]==ch2 and rmp[ch2]==ch1)) return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string& s: words){
            if(match(s,pattern)) ans.push_back(s);
        }
        return ans;
    }
};