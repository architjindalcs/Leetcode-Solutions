class Solution {
public:
    vector<string> ans;
    void helper(string s,int idx){
        if(idx==s.size()) {
            ans.push_back(s);
            return;
        }
        if(!isalpha(s[idx])){
            helper(s,idx+1); //directly call to the next index..
        }
        else{
            helper(s,idx+1); //call as it is..
            char ch=s[idx];
            char temp;
            if(isupper(ch)) temp=tolower(ch);
            else temp=toupper(ch);
            s[idx]=temp;
            helper(s,idx+1);
            s[idx]=ch;
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper(s,0);
        return ans;
    }
};