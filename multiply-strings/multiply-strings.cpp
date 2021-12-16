class Solution {
public:
    string multiply(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        int dp[n1+n2];
        memset(dp,0,sizeof(dp));
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int mul=(s1[i]-'0')*(s2[j]-'0')+dp[i+j+1];
                dp[i+j+1]=mul%10;
                dp[i+j]+=(mul/10);
            }
        }
        string ans="";
        for(int i=0;i<n1+n2;i++) ans+=to_string(dp[i]);
        int i=0;
        while(i<ans.size() and ans[i]=='0') i++;
        if(i==ans.size()) return "0";
        return ans.substr(i);
    }
};