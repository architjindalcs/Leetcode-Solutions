class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    void helper(string& s,string cs,int idx){
        if(idx==s.size()){
            ans.push_back(cs.substr(1));
            return;
        }
        string temp="";
        for(int i=idx;i<s.size();i++){
            temp+=(s[i]);
            if(st.count(temp)){
                helper(s,cs+" "+temp,i+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st=unordered_set<string> (wordDict.begin(),wordDict.end());
        helper(s,"",0);
        return ans;
    }
};