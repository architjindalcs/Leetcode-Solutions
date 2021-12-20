class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0,ans=0,i=0;
        while(i<s.size()){
            char ch=s[i];
            int cnt=0;
            while(i<s.size() and s[i]==ch){
                cnt++;
                i++;
            }
            ans+=min(prev,cnt);
            prev=cnt;
        }
        return ans;
    }
};