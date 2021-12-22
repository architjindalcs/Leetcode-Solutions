class Solution {
public:
    string rmv(string s){
        int i=0;
        string temp="";
        while(i<s.size()){
            if(s[i]!='*'){
                temp+=s[i++];
            }
            else{
                temp+="*";
                while(i<s.size() and s[i]=='*')
                    i++;
            }
        }
        return temp;
    }
    bool isMatch(string s, string p) {
        p=rmv(p);
      //  cout<<"p: "<<p<<endl;
        int n1=s.size(),n2=p.size();
        bool dp[n1+1][n2+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true; 
        for(int i=2;i<=n2;i++) dp[0][i]=(p[i-1]=='*' and dp[0][i-2]);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==p[j-1] or p[j-1]=='.') dp[i][j]=dp[i-1][j-1]; //. can match any character..
                else if(p[j-1]=='*'){
                    dp[i][j]=(dp[i][j-2]); //case of zero matches..
                    if (s[i-1]==p[j-2] or p[j-2]=='.')
                        dp[i][j]=dp[i][j] or dp[i-1][j];
                }
                else dp[i][j]=false;
            }
        }
        return dp[n1][n2];
    }
};