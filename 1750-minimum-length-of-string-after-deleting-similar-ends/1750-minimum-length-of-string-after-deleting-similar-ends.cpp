class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        int ans=s.size();
        while(i<j){
            if(s[i]!=s[j]) return ans; //we can't proceed..
            char ch=s[i];
            while(i<j and s[i]==ch){
                i++;
                ans--;
            }
            while(i<=j and s[j]==ch){
                j--;
                ans--;
            }
        }
        return ans;
    }
};