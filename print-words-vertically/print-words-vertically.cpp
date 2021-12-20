class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int i=0,c=0;
        string cs="";
        while(i<s.size()){
            if(s[i]==' '){
                words.push_back(cs);
                c=max(c,(int)cs.size());
                cs="";
                i++;
            }
            else cs+=s[i++];
        }
        c=max(c,(int)cs.size());
        words.push_back(cs);
        vector<string> ans;
        for(int col=0;col<c;col++){
            string temp="";
            for(int i=0;i<words.size();i++){
                if(col<words[i].size()) temp.push_back(words[i][col]);
                else temp+=" ";
            }
            int idx=temp.size()-1;
            while(idx>=0 and temp[idx]==' ') 
                idx--;
            //ab__d__
            ans.push_back(temp.substr(0,idx+1));
        }
        return ans;
    }
};