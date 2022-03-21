class Solution {
public:
    vector<string> ans;
    
    void helper(int open,int closed,int n,string cs){
        if(open==n and closed==n){
            ans.push_back(cs);
            return;
        }
        //i can use open bracket anytime...if open<n
        if(open<n)
            helper(open+1,closed,n,cs+"(");
        if(open>closed)
            helper(open,closed+1,n,cs+")");
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return ans;
    }
};