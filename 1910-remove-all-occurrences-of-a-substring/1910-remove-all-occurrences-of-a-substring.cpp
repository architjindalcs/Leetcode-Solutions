class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            bool f=false;
            string temp="";
            for(int i=0;i<s.size();i++){
                if(!f and i+part.size()-1<=s.size()-1 and s.substr(i,(int)part.size())==part){
                    f=true;
                    i+=(part.size()-1);
                }
                else temp+=s[i];
            }
          //  cout<<"temp: "<<temp<<endl; 
            if(!f) return temp;
            s=temp;
        }
        return "";
    }
};