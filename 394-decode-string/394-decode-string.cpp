class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string revstr="";
                while(st.top()!='['){
                    revstr+=(st.top());
                    st.pop();
                }
                st.pop();
                int rep=0,mulf=1;
                while(st.size() and (st.top()>='0' and st.top()<='9')){
                    rep+=(mulf*(st.top()-'0'));
                    mulf*=10;
                    st.pop();
                }
                while(rep--){
                    for(int j=revstr.size()-1;j>=0;j--){
                        st.push(revstr[j]);
                    }
                }
            }
            else st.push(s[i]);
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};