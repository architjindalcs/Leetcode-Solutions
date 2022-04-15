class Solution {
public:
    vector<string> helper(string& s){
        int i=0;
        string cs="";
        vector<string> ans;
        while(i<=s.size()){
            if(i==s.size() or s[i]==' '){
                ans.push_back(cs);
                cs="";
                i++;
            }
            else cs+=s[i++];
        }
        return ans;
    }
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size()) return areSentencesSimilar(s2,s1);
        
        vector<string> v1=helper(s1);
        vector<string> v2=helper(s2);
        if(v1.size()==v2.size()) return v1==v2;
        int n2=v2.size(),i=0;
        //n2-> small wala..
        while(i<n2 and v1[i]==v2[i]){
            i++;
        }
        // i
        // i am doing leetcode haha
        // i leetcode haha
        int idx=v1.size()-(v2.size()-i);
        while(idx<v1.size() and i<n2 and v1[idx]==v2[i]){
            i++;
            idx++;
        }
        return i==v2.size();
    }
};