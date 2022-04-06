class Solution {
public:
    int helper(string& s,int l,int r){
        int f[26];
        memset(f,0,sizeof(f));
        for(int i=l;i<=r;i++) f[s[i]-'a']++;
        int maxf=INT_MIN,minf=INT_MAX;
        for(int i=0;i<26;i++){
            if(f[i]){
                if(f[i]>maxf) maxf=f[i];
                if(f[i]<minf) minf=f[i];
            }
        }
        return maxf-minf;
    }
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                ans+=helper(s,i,j);
            }
        }
        return ans;
    }
};