class Solution {
public:
    vector<int> ans;
    void helper(string& s,int idx,vector<int>& path){
        if(idx==s.size()){
            if(path.size()>=3)
            ans=path;
            return;
        }
        
        int n=path.size();
        if(ans.size()) return;
        if(s[idx]=='0'){
            //leading zeros are not allowed..
            if(path.size()<2 or (long)path[n-1]+path[n-2]==0){
                path.push_back(0);
                helper(s,idx+1,path);
                path.pop_back();
            }
            return;
        } 
        long cs=0;
        for(int i=idx;i<s.size();i++){
            cs=cs*10+(s[i]-'0');
            if(cs>INT_MAX) break;
            if(path.size()<2 or (long)path[n-1]+path[n-2]==cs){
                path.push_back(cs);
                helper(s,i+1,path);
                path.pop_back();
            }
        }
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> path;
        helper(num,0,path);
        return ans;
    }
};