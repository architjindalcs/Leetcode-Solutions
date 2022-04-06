class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        int i=0;
        string cs="";
        int cnt=0;
        while(i<s.size()){
            cs+=s[i++];
            cnt++;
            if(cnt==k or i==s.size()){
                v.push_back(cs);
                cs="";
                cnt=0;
            }
        }
        if(v.back().size()!=k){
            string last=v.back();
            last+=(string(k-(int)v.back().size(),fill));
            v.back()=last;
        }
        return v;
    }
};