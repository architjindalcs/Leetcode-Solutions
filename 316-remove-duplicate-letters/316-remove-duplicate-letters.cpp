class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> f(26,0);
        for(char ch: s) f[ch-'a']++;
        vector<bool> used(26,false);
        
        for(char ch: s){
            f[ch-'a']--;
            if(used[ch-'a']) continue;
            
            used[ch-'a']=true;
            
            while(st.size() and st.top()>ch and f[st.top()-'a']){
                char ch=st.top();
                st.pop();
                used[ch-'a']=false;
            }
            st.push(ch);
        }
        string ans="";
        while(st.size()){
            ans+=(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};