class Solution {
public:
    unordered_set<string> st;
    int calls=0;
    vector<string> helper(string& s,int idx){
        if(idx==s.size()) return vector<string> {""};
        calls++;
        string cs="";
        vector<string> ans;
        for(int i=idx;i<s.size();i++){
            cs+=s[i];
            if(st.count(cs)){
                vector<string> next=helper(s,i+1);
                for(string ns: next){
                    if(ns!="") ans.push_back(cs+" "+ns);
                    else ans.push_back(cs);
                }
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st=unordered_set<string>(wordDict.begin(),wordDict.end());
        vector<string> ans=helper(s,0);
       // cout<<"calls: "<<calls<<endl;
        return ans;
    }
};