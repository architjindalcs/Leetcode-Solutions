class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,cs=0,st=0;
        int ans=0;
        while(i<s.size()){
            cs+=abs(s[i]-t[i]);
            while(st<i and cs>maxCost){
                cs-=abs(s[st]-t[st]);
                st++;
            }
            if(cs<=maxCost) ans=max(ans,i-st+1);
            i++;
        }
        return ans;
    }
};