class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int,string> m;
        int i=0;
        string cs="";
        while(i<=s.size()){
            if(i==s.size() or s[i]==' '){
                m[cs.back()-'1']=cs.substr(0,(int)cs.size()-1);
                cs="";
                i++;
            }
            else cs+=s[i++];
        }
        string ans="";
        int n=m.size();
        for(int i=0;i<n;i++){
            ans+=(m[i]);
            if(i!=n-1) ans+=" ";
        }
        return ans;
    }
};