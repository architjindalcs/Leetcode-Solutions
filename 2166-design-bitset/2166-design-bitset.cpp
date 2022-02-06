class Bitset {
public:
    unordered_set<int> ones;   //indices where 1 is there..
    unordered_set<int> zeros;  //indices where 0 is there..
    int size;
    Bitset(int size) {
        this->size=size;
        for(int i=0;i<size;i++)
            zeros.insert(i);
    }
    
    void fix(int idx) {
        if(zeros.count(idx)) zeros.erase(idx);
        ones.insert(idx);
    }
    
    void unfix(int idx) {
        if(ones.count(idx)) ones.erase(idx);
        zeros.insert(idx);
    }
    
    void flip() {
        swap(ones,zeros);
    }
    
    bool all() {
        return ones.size()==size;
    }
    
    bool one() {
        return ones.size()>=1;
    }
    
    int count() {
        return ones.size();
    }
    
    string toString() {
        string ans="";
        for(int i=0;i<size;i++){
            if(ones.count(i)) ans+="1";
            else ans+="0";
        }
        return ans;
    }
};
