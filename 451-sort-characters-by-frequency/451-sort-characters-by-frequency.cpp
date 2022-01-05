class Solution {
public:
    string frequencySort(string s) {
        int f[256];
        memset(f,0,sizeof(f));
        for(char ch: s) f[ch]++;
        vector<pair<char,int>> v;
        for(int i=0;i<256;i++){
            if(!f[i]) continue;
            char ch=(char)i;
            v.push_back({ch,f[i]});
        }
        sort(v.begin(),v.end(),[&](pair<char,int>& p1,pair<char,int>& p2){
            return p1.second>p2.second;
        });
        string ans="";
        for(pair<char,int>& p: v){
            char ch=p.first; int f=p.second;
            while(f--) ans+=ch;
        }
        return ans;
    }
};