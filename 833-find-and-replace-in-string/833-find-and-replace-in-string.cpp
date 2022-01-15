class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int,pair<int,string> > m;  //index,len -> mapping....
        for(int i=0;i<indices.size();i++){
            int idx=indices[i];
            string src=sources[i],targ=targets[i];
            int len=src.size();
            if(idx+len-1<=s.size()-1){
                if(s.substr(idx,len)==src){
                    m[idx]={len,targ};
                }
            }
        }
        string ans="";
        int i=0;
        while(i<s.size()){
            if(m.count(i)){
                int len=m[i].first;
                string ns=m[i].second;
                ans+=ns;
                i+=(len);
            }
            else ans+=(s[i++]);
        }
        return ans;
    }
};