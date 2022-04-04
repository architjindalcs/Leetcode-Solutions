class Solution {
public:
    bool valid(vector<int>& f,int k){
        int maxF=0;
        int cnt=0;
        for(int i: f){
            maxF=max(maxF,i);
            cnt+=i;
        }
        return cnt-maxF<=k;
    }
    int characterReplacement(string s, int k) {
        int maxLen=0,i=0,st=0;
        vector<int> f(26,0);
        int maxf=0,cntChars=0;
        while(i<s.size()){
            f[s[i]-'A']++;
            maxf=max(maxf,f[s[i]-'A']);
            cntChars++;
            
            while(st<i and !(cntChars-maxf<=k)){
                f[s[st]-'A']--;
                cntChars--;
                
                st++;
            }
            if(cntChars-maxf<=k){
                maxLen=max(maxLen,i-st+1);
            }
            i++;
        }
        return maxLen;
    }
};