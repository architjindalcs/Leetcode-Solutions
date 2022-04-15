class Solution {
public:
    int longestBeautifulSubstring(string s) {
        string vowels="aeiou";
        int ans=0,i=0;
        while(i<s.size()){
            if(s[i]!='a'){
                i++;
                continue;
            }
            //i got a 'a' !!!!
            int len=0,idx=0;;
            
            while(idx<vowels.size()){
                if(s[i]!=vowels[idx]) break;
                while(i<s.size() and s[i]==vowels[idx]) {
                    i++;
                    len++;
                }
                idx++;
            }
            
            if(idx==vowels.size())
            ans=max(ans,len);
        }
        return ans;
    }
};