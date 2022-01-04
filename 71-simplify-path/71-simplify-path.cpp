class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int i=0;
        string cs="";
        while(i<=path.size()){
            if(i==path.size() or path[i]=='/'){
                if(cs.size()){
                    if(cs=="."){
                        //single dot, current directory..
                        //no issue, let that go..
                    }
                    else if(cs==".."){
                        //up directory if possible...
                        if(st.size()) st.pop_back(); //pop from the stack..
                    }
                    else{
                        //its a folder name ..
                        st.push_back(cs);  //push the folder na,e.
                    }
                }
                cs="";
                i++;
            }
            else cs+=path[i++];
        }
        string ans="/";
        for(string& s: st) {
            ans+=s+"/";
        }
        if(ans=="/") return ans;
        ans.pop_back();
        return ans;
    }
};