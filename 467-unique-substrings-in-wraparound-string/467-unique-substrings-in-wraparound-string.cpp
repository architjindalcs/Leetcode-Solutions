class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        int i=0;
        while(i<p.size()){
            if(i<p.size()-1){
                cnt[p[i]-'a']=max(cnt[p[i]-'a'],1);
                i++;
                int c=1;
                while(i<p.size() and (p[i]-p[i-1]==1 or p[i]-p[i-1]==-25)){
                    c++;
                    cnt[p[i]-'a']=max(cnt[p[i]-'a'],c);
                    i++;
                }
            }
            else {
                cnt[p[i]-'a']=max(cnt[p[i]-'a'],1);
                i++;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++) ans+=cnt[i];
        return ans;
    }
};