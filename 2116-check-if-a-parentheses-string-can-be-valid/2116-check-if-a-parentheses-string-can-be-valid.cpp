class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1) return false;
        int bal=0;
        //Ist iteration we check  ((() -> good,  ()))) -> bad
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') bal++;
            else if(locked[i]=='0'){
                bal++;
                //it may be ( , )  -> no matter we can change to otherwise..
            }
            else bal--;
            if(bal<0) return false;
        }
        //checking for  reverse mod, ((()) -> bad,  ()))))-> good
        bal=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') bal++;
            else if(locked[i]=='0') bal++;
            else bal--;
            if(bal<0) return false;
        }
        return true;
    }
};