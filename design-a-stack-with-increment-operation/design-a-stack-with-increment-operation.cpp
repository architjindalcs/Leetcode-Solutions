class CustomStack {
public:
    stack<int> st;
    int maxSiz;
    vector<int> inc;
    CustomStack(int maxSize) {
        maxSiz=maxSize;
        inc=vector<int> (maxSize,0);
    }
    
    void push(int x) {
        if(st.size()==maxSiz) return;
        st.push(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int tp=st.top();
        int idx=st.size()-1;
        st.pop();
        int ans=tp+inc[idx];
        if(idx) inc[idx-1]+=inc[idx];
        inc[idx]=0;
        return ans;
    }
    
    void increment(int k, int val) {
        if(st.empty()) return;
        int idx=min((int)st.size()-1,k-1);
        inc[idx]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */