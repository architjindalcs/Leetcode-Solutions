class Solution {
public:
    int countCollisions(string s) {
        int i=0;
        while(i<s.size() and s[i]=='L') i++;         
        int j=s.size()-1;
        while(j>=0 and s[j]=='R') j--;

        int ans=0;
        
        //RRRLSL
        for(int z=i;z<=j;z++) ans+=(s[z]!='S');
        return ans;
    }
};