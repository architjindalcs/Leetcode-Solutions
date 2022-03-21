class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<string> v;
        int i=0;
        while(i<s.size()){
            if(s[i]>='0' and s[i]<='9'){
                //it is a number..
                string cs="";
                while(i<s.size() and s[i]>='0' and s[i]<='9')
                    cs+=s[i++];
                v.push_back(cs);
            }
            else v.push_back(string(1,s[i++]));
        }
        int n=v.size();
        vector<int> dp[n][n];
        for(int i=0;i<n;i+=2) dp[i][i]={stoi(v[i])};
        for(int l=3;l<=n;l+=2){
            // 2-1-1
            // i   k
            //
            for(int i=0;i<=(n-l);i+=2){
                int k=i+l-1;
                for(int z=i+1;z<=k;z+=2){
                    string sign=v[z];
                    vector<int> left=dp[i][z-1];
                    vector<int> right=dp[z+1][k];
                    for(int l: left){
                        for(int r: right){
                            if(sign=="+")
                                dp[i][k].push_back(l+r);
                            else if(sign=="-")
                                dp[i][k].push_back(l-r);
                            else dp[i][k].push_back(l*r);
                        }
                    }      
                }
            }
        }
        return dp[0][n-1];
        
    }
};