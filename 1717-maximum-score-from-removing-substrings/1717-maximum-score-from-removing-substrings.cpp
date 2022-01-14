class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x>y){
            //ab ko remove krne pe jyada points milre h...hahahah
            string st;
            int ans=0;
            for(char ch: s){
                if(ch=='b'){
                    if(st.size() and st.back()=='a'){
                        ans+=(x);
                        st.pop_back();
                    }
                    else st.push_back(ch);
                }
                else st.push_back(ch);
            }
            
            string temp="";
            for(char ch: st){
                if(ch=='a'){
                    if(temp.size() and temp.back()=='b'){
                        ans+=y;
                        temp.pop_back();
                    }
                    else temp.push_back(ch);
                }
                else temp.push_back(ch);
            }
            return ans;
        }
         string st;
            int ans=0;
            for(char ch: s){
                if(ch=='a'){
                    if(st.size() and st.back()=='b'){
                        ans+=(y);
                        st.pop_back();
                    }
                    else st.push_back(ch);
                }
                else st.push_back(ch);
            }
            
            string temp="";
            for(char ch: st){
                if(ch=='b'){
                    if(temp.size() and temp.back()=='a'){
                        ans+=x;
                        temp.pop_back();
                    }
                    else temp.push_back(ch);
                }
                else temp.push_back(ch);
            }
            return ans;
    }
};