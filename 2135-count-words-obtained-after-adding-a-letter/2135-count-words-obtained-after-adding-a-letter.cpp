class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> st;
        for(string& s: startWords){
            int mask=0;
            for(char ch: s){
                int c=ch-'a';
                mask=mask | (1<<c); 
            }
            st.insert(mask);
        }
        int ans=0;
        for(string& s: targetWords){
            int mask=0;
            for(char ch: s){
                int c=ch-'a';
                mask=mask | (1<<c);
            }
            bool f=false;
            for(int i=31;i>=0;i--){
                if(mask&(1<<i)){
                    int temp=mask & (~(1<<i));
                    if(st.count(temp)){
                        f=true;
                        break;
                    }
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};