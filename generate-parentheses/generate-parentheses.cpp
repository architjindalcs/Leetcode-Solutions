class Solution {
public:
    vector<string> ans;
    int n;
    void helper(string cs,int lused,int rused){
        if(lused==n and rused==n){
            ans.push_back(cs);
            return;
        }
        if(lused==n){
            helper(cs+")",lused,rused+1);
            return;
        }
        helper(cs+"(",lused+1,rused);
        if(lused>rused){
            helper(cs+")",lused,rused+1);
            //left parenthesis are less 
        }
    }
    vector<string> generateParenthesis(int nn) {
        n=nn;
        helper("",0,0);
        return ans;
    }
};