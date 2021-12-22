class Solution {
public:
    int romanToInt(string s) {
        vector<int> v={1,5,10,50,100,500,1000};
        string ss="IVXLCDM";
        unordered_map<char,int> m;
        for(int i=0;i<v.size();i++) m[ss[i]]=v[i];
        int ans=0,i=s.size()-1;
        for(;i>=1;i--){
            ans+=m[s[i]];
            if(m[s[i-1]]<m[s[i]]) {
                ans-=m[s[i-1]];
                i--;
            }
        }
        ans+=(i==0? m[s[0]]: 0);
        return ans;
    }
};