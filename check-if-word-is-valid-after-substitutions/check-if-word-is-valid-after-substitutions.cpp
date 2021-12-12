class Solution {
public:
    bool isValid(string s) {
        string res="";
        for(char ch: s){
            /*
                aabcbc
            */
            if(res.size()<2)
                res.push_back(ch);
            else{
                if(ch=='c'){
                    int n=res.size();
                    char slast=res[n-2];
                    int last=res[n-1];
                    if(!(last=='b' and slast=='a'))
                        return false;
                    res.pop_back();
                    res.pop_back();
                }
                else res.push_back(ch);
            }
        }
        return res.empty();
    }
};