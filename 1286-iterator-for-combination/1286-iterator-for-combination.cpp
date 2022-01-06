class CombinationIterator {
public:
    vector<string> v;
    int idx=0;
    void helper(string&s ,int idx,string cs,int len){
        if(cs.size()==len){
            v.push_back(cs);
            return;
        }
        if(idx==s.size()) return;
        for(int i=idx;i<s.size();i++){
            cs.push_back(s[i]);
            helper(s,i+1,cs,len);
            cs.pop_back();
        }
    }
    CombinationIterator(string s, int len) {
        sort(s.begin(),s.end());
        helper(s,0,"",len);
    }
    
    string next() {
       return v[idx++];
    }
    
    bool hasNext() {
        return idx<=v.size()-1;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */