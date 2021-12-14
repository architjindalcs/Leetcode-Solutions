class Solution {
public:
    
    int maxConsecutiveAnswers(string s, int k) {
        //longest subarray with atmost k differences..
        int ans=0;
        int i=0,st=0,cnt=0;
        while(i<s.size()){
            if(s[i]=='F') cnt++;
            while(st<i and cnt>k){
                cnt-=(s[st]=='F');
                st++;
            }
            if(cnt<=k)
            ans=max(ans,i-st+1);
            i++;
        }
        
        i=0;
        st=0;
        cnt=0;
        while(i<s.size()){
            if(s[i]=='T') cnt++;
            while(st<i and cnt>k){
                cnt-=(s[st]=='T');
                st++;
            }
            if(cnt<=k)
            ans=max(ans,i-st+1);
            i++;
        }
        return ans;
    }
};