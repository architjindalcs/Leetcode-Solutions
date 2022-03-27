class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n=text.size();
        int cntCh1=1;
        int cntCh2=0;
        long long ans=0;
        long long cnt1=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==pattern[1]){
                cnt1+=(cntCh1);
            }
            if(text[i]==pattern[0]){
                cntCh1++;
            }
        }
        cntCh2=1;
        long long cnt2=0;
        for(int i=text.size()-1;i>=0;i--){
            
            if(text[i]==pattern[0]){
                cnt2+=(cntCh2);
            }
            if(text[i]==pattern[1]){
                cntCh2++;
            }

        }
        return max(cnt1,cnt2);
    }
};