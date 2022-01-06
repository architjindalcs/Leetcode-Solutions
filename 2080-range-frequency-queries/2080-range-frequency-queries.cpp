class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(!m.count(value)) return 0;
        int idx1=upper_bound(m[value].begin(),m[value].end(),right)-m[value].begin();
        idx1--;
        if(idx1==-1) return 0; 
        
        int idx2=lower_bound(m[value].begin(),m[value].end(),left)-m[value].begin();
        if(idx2==m[value].size()) return 0; //saare elements array ke left se chote h..
        return idx1-idx2+1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */