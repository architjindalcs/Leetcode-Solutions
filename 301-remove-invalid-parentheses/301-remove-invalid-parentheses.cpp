class Solution {
public:
    bool valid(string s){
        int left=0,right=0;
        for(char& ch: s) {
            if(ch=='(') left++;
            else if(ch==')'){
                if(!left) return false;
                left--;
            }
        }
        return left==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        while(q.size()){
            int siz=q.size();
            bool fnd=false;
            vector<string> clevel;
            while(siz--){
                string fr=q.front();
                q.pop();
                
                if(valid(fr)){
                   clevel.push_back(fr);
                    fnd=true;
                }
                if(fnd) continue;
                
                for(int i=0;i<fr.size();i++){
                    if(!(fr[i]=='(' or fr[i]==')')) continue;
                    string temp=fr.substr(0,i)+ fr.substr(i+1); 
                    if(!vis.count(temp)){
                        vis.insert(temp);
                        q.push(temp);
                    }
                }
            }
            if(fnd) return clevel;
        }
        return {};
    }
};