class Solution {
public:
    bool hasdot(string& s){
        for(char ch: s) {
            if(ch=='.') return true;
        }
        return false;
    }
    bool validv4(string s){
        //3 + [4-12] = [7-15]
        int n=s.size();
        if(!(n>=4 and n<=15)) return false;
        
        int cntDots=0;
        
        s+=".";
        string cs="";
        for(char& ch: s){
            if(!((ch>='0' and ch<='9') or (ch=='.'))) return false;
            if(ch==':') return false;
            
            if(ch=='.'){
                cntDots++;
                if(cs.empty()) return false;
                if(cs.size()>3) return false;
                if(cs[0]=='0' and cs.size()!=1) return false;
                
                int val=stoi(cs);
                if(!(val>=0 and val<=255)) return false;
                cs="";
            }
            else cs+=ch;
        }
        return cntDots==4;
    }
    bool validv6(string s){
        int n=s.size();  // 7 + [8-32] = 15-39
        if(!(n>=15 and n<=39)) return false;
        s+=":";
        string cs="";
        int cntDots=0;
        for(char& ch: s){
            if(ch=='.') return false;
            if(!((ch>='0' and ch<='9') or (ch>='A' and ch<='F') or (ch>='a' and ch<='f') or (ch==':'))) return false;
            
            if(ch==':'){
                cntDots++;
                if(cs.empty()) return false;
                if(cs.size()>4) return false;
                cs="";
            }
            else cs+=ch;
        }
        return cntDots==8;
    }
    string validIPAddress(string queryIP) {
        if(hasdot(queryIP)){
            if(validv4(queryIP)) return "IPv4";
        }
        else{
            if(validv6(queryIP)) return "IPv6";
        }
        return "Neither";
    }
};