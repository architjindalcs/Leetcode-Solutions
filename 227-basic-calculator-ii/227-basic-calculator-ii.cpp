class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                continue; 
            }
            if(s[i]>='0' and s[i]<='9'){
                //it is a digit, mtlb ek no generate hoga ab..
                int num=0;
                while(i<s.size() and s[i]>='0' and s[i]<='9'){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i-=1;
                if(sign==1) st.push(num);
                else if(sign==-1) st.push(-num);
            }
            else if(s[i]=='+') sign=1;
            else if(s[i]=='-') sign=-1;  
            else if(s[i]=='*') {
                int tp=st.top();
                st.pop();
                while(!(s[i]>='0' and s[i]<='9')) i++;
                int num=0;
                while(i<s.size() and s[i]>='0' and s[i]<='9'){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i--;
                st.push(tp*num);
            }
            else{
                int tp=st.top();
                st.pop();
                i++;
                int num=0;
                while(!(s[i]>='0' and s[i]<='9')) i++;
                while(i<s.size() and s[i]>='0' and s[i]<='9'){
                    num=num*10+(s[i]-'0');
                    i++;
                } 
                i--;
                st.push(tp/num);
            }
        }
        int ans=0;
        while(st.size()){
            ans+=(st.top());
            st.pop();
        }
        return ans;
    }
};