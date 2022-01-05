class Solution {
public:
    vector<string> ans;
    void helper(string& s,int idx,string cs,int dots){
        if(idx==s.size()){
            if(dots==0){
                ans.push_back(cs.substr(0,(int)cs.size()-1));
            }
            return;
        }
        if(s[idx]=='0'){
            helper(s,idx+1,cs+"0.",dots-1);
            return;
        }
        int val=0;
        string css="";
        for(int i=idx;i<min((int)s.size(),idx+3);i++){
            val=val*10+(s[i]-'0');
            css.push_back(s[i]);
            if(val>=0 and val<=255){
                helper(s,i+1,cs+css+".",dots-1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        helper(s,0,"",4);
        return ans;
    }
};