class MinStack {
public:
    long minEle;
    stack<long> st;
    MinStack() {
        
    }
    
    void push(long x) {
        if(st.empty()){
            st.push(x);
            minEle=x;
            return;
        }
        /*
            x<minEle;
            x-minEle<0
            2*x-minEle<x
        */
        if(x<minEle){
            st.push(2*(long)x-minEle);
            minEle=x;
        }
        else st.push(x);
    }
    
    void pop() {
        long tp=st.top();
        st.pop();
        if(tp<minEle){
            minEle=2*minEle-tp;
        }
    }
    
    int top() {
        long tp=st.top();
        if(tp<minEle) return minEle;
        return tp;
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */