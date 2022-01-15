class Solution {
public:
    string decodeAtIndex(string s, int k) {
        k--;
        long long len=0;
        for(char ch: s){
            if(ch>='0' and ch<='9'){
                len=len*(ch-'0');
            }
            else len++;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>='0' and s[i]<='9'){
                int c=(s[i]-'0');
                len/=c;
                k=k%len;
            }
            else{
                if(k==len-1){
             //       cout<<s[i]<<endl;
                    return string(1,s[i]);
                }
                len--;
            }
        }
        return "";
    }
};