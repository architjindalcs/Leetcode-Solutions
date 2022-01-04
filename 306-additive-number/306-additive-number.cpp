class Solution {
public:
    vector<uint64_t> ans;
    void helper(string& s,int idx,vector<uint64_t>& path){
        if(idx==s.size()){
            if(path.size()>=3)
            ans=path;
            return;
        }
        int n=path.size();
        if(ans.size()) return;
        if(s[idx]=='0'){
            //leading zeros are not allowed..
            if(path.size()<2 or path[n-1]+path[n-2]==0){
                path.push_back(0);
                helper(s,idx+1,path);
                path.pop_back();
            }
            return;
        } 
        uint64_t cs=0;
        for(int i=idx;i<s.size();i++){
            cs=cs*10+(s[i]-'0');
            if(path.size()<2 or path[n-1]+path[n-2]==cs){
                path.push_back(cs);
                helper(s,i+1,path);
                path.pop_back();
            }
        }
    }
    bool isAdditiveNumber(string num) {
        vector<uint64_t> path;
        helper(num,0,path);
        return ans.size()>=3;
    }
};