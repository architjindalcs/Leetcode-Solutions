class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> st;
        for(string& s: words){
            vector<int> v(52,0);
            for(int i=0;i<s.size();i++){
                if(i&1)
                    v[s[i]-'a']++;
                else v[s[i]-'a'+26]++;
            }
            string tmp="";
            for(int i: v) tmp+=to_string(i);
            st.insert(tmp);
        }
        return st.size();
    }
};