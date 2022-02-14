class Solution {
public:
    int titleToNumber(string s) {
        long mulf=1,ans=0;
        for(int i=s.size()-1;i>=0;i--){
            ans+=(s[i]-'A'+1)*mulf;
            mulf*=26;
        }
        return ans;
    }
};