class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/"){
                int tp1=st.top();
                st.pop();
                int tp2=st.top();
                st.pop();
                if(tokens[i]=="+") st.push(tp2+tp1);
                else if(tokens[i]=="-") st.push(tp2-tp1);
                else if(tokens[i]=="*") st.push(tp2*tp1);
                else st.push(tp2/tp1);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};