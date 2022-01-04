class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res=0,sign=1;  //sign is postive..
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;  
            if(s[i]=='('){
                st.push(res);
                st.push(sign);
                sign=1;
                res=0;
            }
            else if(s[i]==')'){
                int signVal=st.top();
                st.pop();
                int prevRes=st.top();
                st.pop();
                res=res*signVal;
                res+=prevRes;
                sign=1;
            } 
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else{
                //now its a number..
                int num=0;
                while(i<s.size() and s[i]>='0' and s[i]<='9'){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i--;
                res+=(sign*num);
            }
        }
        return res;
    }
};