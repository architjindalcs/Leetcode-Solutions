class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<s.size();i++){
            int l=i,r=i;  //considering odd length palindromes..
            //ar[a]ra
            while(l>=0 and r<s.size() and s[l]==s[r]){
                l--;
                r++;
                cnt++;
            }
            //[ar][a]ra
            l=i-1,r=i;
            while(l>=0 and r<s.size() and s[l]==s[r]){
                l--;
                r++;
                cnt++;
            }
        }
        return cnt;
        // bool dp[n][n];
        // memset(dp,false,sizeof(dp));
        // int ans=n;
        // for(int i=0;i<n;i++) dp[i][i]=true;
        // for(int l=2;l<=n;l++){
        //     for(int i=0;i<=(n-l);i++){
        //         int k=i+l-1;
        //         dp[i][k]=(l==2? (s[i]==s[k]): (s[i]==s[k] and dp[i+1][k-1]));
        //         ans+=dp[i][k];
        //     }
        // }
        // return ans;
    }
};