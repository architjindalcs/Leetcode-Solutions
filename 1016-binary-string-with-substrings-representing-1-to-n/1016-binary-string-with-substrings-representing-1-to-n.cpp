class Solution {
public:
    string getBin(int n){
        string ans="";
        while(n){
            //1110  -> 7
            ans+=to_string(n%2);
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() and ans[i]=='0') i++;
        return i==ans.size()? "0" : ans.substr(i);
    }
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            int idx=s.find(getBin(i));
            if(idx==-1) return false;
        }
        return true;
    }
};