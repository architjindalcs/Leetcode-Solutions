class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp="";
        int cnt=0;
        while(temp.size()<b.size()){
            temp+=a;
            cnt++;
        }
        if(temp.find(b)!=-1) return cnt;
        temp+=a;
        if(temp.find(b)!=-1) return cnt+1;
        return -1;
    }
};