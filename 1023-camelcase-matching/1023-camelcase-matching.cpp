class Solution {
public:
    bool match(string& s,string& p){
        if(p.size()>s.size()) return false;
        int i=0;
        for(char ch: s){
            if(ch>='A' and ch<='Z'){
                if(i<p.size() and p[i]==ch){
                    i++;
                }
                else return false;
            }
            else{
                if(i<p.size() and p[i]==ch) {
                    i++;
                }
            }
        }
        return i==p.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string& s: queries){
            ans.push_back(match(s,pattern));
        }
        return ans;
    }
};