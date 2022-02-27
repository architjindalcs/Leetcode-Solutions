class Solution {
public:
    bool help(string& s1,string& s2){
        int i=0,j=0;
        while(i<s1.size() and j<s2.size() and s1[i]==s2[j]){
            i++;
            j++;
        }
        return j==s2.size();
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto& s: words){
            ans+=(help(s,pref));
        }
        return ans;
    }
};