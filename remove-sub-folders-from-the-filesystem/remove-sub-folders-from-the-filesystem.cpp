class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),[&](string& s1,string& s2){
            return s1.size()!=s2.size()? s1.size()<s2.size(): s1<s2;   
        });
        
        unordered_set<string> st;
        for(string& s: folder){
            bool fnd=false;
            string temp="";
            for(int i=0;i<s.size()-1;i++){
                temp+=s[i];
                if(s[i+1]=='/'){
                    if(st.count(temp)){
                        fnd=true;
                        break;
                    }
                }
            }
            if(!fnd)
            st.insert(s);
        }
        return vector<string> (st.begin(),st.end());
    }
};