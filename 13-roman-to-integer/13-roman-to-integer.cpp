class Solution {
public:
    int romanToInt(string ss) {
        unordered_map<char,int> m;
        string s="IVXLCDM";
        vector<int> v={1,5,10,50,100,500,1000};
        int i=ss.size()-1;
        for(int j=0;j<v.size();j++) m[s[j]]=v[j];
        int ans=0;
        while(i>0){
            ans+=m[ss[i]];
            if(i-1>=0 and m[ss[i-1]]<m[ss[i]]) {
                ans-=m[ss[i-1]];
                i--;
            }
            i--;
        }
        if(i>=0) ans+=m[ss[i]];
        return ans;
    }
};