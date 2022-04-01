class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hp(256,0),hs(256,0);
        for(char ch: t) hp[ch]++;
        int idx=-1,cnt=0;
        int st=0,minLen=INT_MAX,si=-1;
        int i=0;
        for(char ch: s){
            hs[ch]++;
            if(hs[ch]<=hp[ch]) cnt++;
            
            if(cnt==t.size()){
                //i have got all my required chars..
                
                while(st<i and hs[s[st]]>hp[s[st]]){
                    hs[s[st]]--;
                    st++;
                }
                if(i-st+1<minLen){
                    minLen=i-st+1;
                    si=st;
                }
            }
            i++;
        }
   //     cout<<"minLen: "<<minLen<<endl;
        if(si!=-1) return s.substr(si,minLen);
        return "";
    }
};