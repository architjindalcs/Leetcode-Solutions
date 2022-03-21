class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans=0;
        for(int st=0;st<s.size();st++){
            for(int st2=0;st2<t.size();st2++){
                int i=st,j=st2;
                int cntDiff=0;
                while(i<s.size() and j<t.size()){
                    if(s[i]!=t[j]) cntDiff++;
                    if(cntDiff>1) break;
                    ans+=(cntDiff==1);
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};