class Solution {
public:
    bool valid(string& s){
        int left=0;
        for(char ch: s){
            if(ch=='(') left++;
            else if(ch==')'){
                if(left) left--;
                else return false;
            }
        }
        return left==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        unordered_set<string> vis;
        vector<string> ans;
        vis.insert(s);
        bool go=true;
        while(q.size() and go){
            int siz=q.size();
            while(siz--){
                string fr=q.front();
                q.pop();
                if(valid(fr)){
                    go=false;
                    ans.push_back(fr);
                }
               // cout<<"frrrrrrrrrrrrrrrrrrrrrrrrr: "<<fr<<endl;
                for(int i=0;i<fr.size();i++){
                    if(fr[i]!='(' and fr[i]!=')') continue;
                    string tmp=fr.substr(0,i)+fr.substr(i+1);
               //     cout<<"tmp: "<<tmp<<endl;
                    if(!vis.count(tmp)){
                        q.push(tmp);
                        vis.insert(tmp);
                    }
                }
            }
        }
        return ans;
    }
};