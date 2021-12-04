class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string> mp;
        for(vector<string>& v: knowledge) mp[v[0]]=v[1];
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                string tmp="";
                i++;
                while(s[i]!=')') tmp+=s[i++];
                if(mp.count(tmp)) ans+=mp[tmp];
                else ans+="?";
                i++;
            }
            else ans.push_back(s[i++]);
        }
        return ans;
    }
};