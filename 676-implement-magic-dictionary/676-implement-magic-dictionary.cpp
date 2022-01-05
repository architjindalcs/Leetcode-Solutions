class MagicDictionary {
public:
    unordered_map<int,unordered_set<string>>  st;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dict) {
       // st=unordered_set<string> (dict.begin(),dict.end());
        for(string& s: dict){
            st[(int)s.size()].insert(s);
        }
    }
    
    bool search(string searchWord) {
        int len=searchWord.size();
        if(!st.count(len)) return false;
        for(auto& s: st[len]){
            int cnt=0;
            for(int i=0;i<searchWord.size();i++){
                if(s[i]!=searchWord[i]){
                    cnt++;
                }
            }
            if(cnt==1) return true;
        }
        return false; 
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */