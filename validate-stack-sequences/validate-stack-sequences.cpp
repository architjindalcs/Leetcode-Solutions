class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,j=0;
        while(i<pushed.size() and j<popped.size()){
            st.push(pushed[i++]);
            if(st.top()==popped[j]){
                while(st.size() and j<popped.size() and popped[j]==st.top()){
                    st.pop();
                    j++;
                }
            }
        }
        return i==pushed.size() and j==popped.size() and st.empty();
    }
};