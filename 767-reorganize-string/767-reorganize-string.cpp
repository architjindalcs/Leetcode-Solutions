class Solution {
public:
    string reorganizeString(string s) {
        int f[26];
        memset(f,0,sizeof(f));
        for(char ch: s) f[ch-'a']++;
        vector<pair<char,int>> v;
        for(int i=0;i<26;i++){
            if(!f[i]) continue;
            char ch=i+'a';
            int fr=f[i];
            v.push_back({ch,fr});
        }
        sort(v.begin(),v.end(),[&](pair<char,int>& p1,pair<char,int>& p2){
           return p1.second>p2.second; 
        });
        int maxf=v[0].second;
        int n=s.size();
        if(n%2==0){
            //abab
            if(maxf>n/2) return "";  //not possible
        }
        else{
            //aba
            if(maxf > (n/2)+1) return "";
        }
       // int n=s.size();
        int eidx=0,oidx=1;
        string ans=string(n,'$');
        for(pair<char,int>& p: v){
            char ch=p.first;
            int fr=p.second;
            while(eidx<ans.size() and fr){
                ans[eidx]=ch;
                eidx+=2;
                fr--;
            }
            if(fr){
                while(oidx<ans.size() and fr){
                    ans[oidx]=ch;
                    oidx+=2;
                    fr--;
                }
            }
        }
        return ans;
    }
};