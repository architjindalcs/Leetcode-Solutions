class Solution {
public:
    long long numberOfWays(string s) {
        long long ans=0;  //010  , or 101 
        int ones=0,zeros=0;
        for(char ch: s){
            ones+=(ch=='1');
            zeros+=(ch=='0');
        }
     //   long long ans=0;
        int pz=(s[0]=='0'),po=(s[0]=='1');
        for(int i=1;i<s.size()-1;i++){
            if(s[i]=='0'){
                 //101 wale
                
                int no=ones-po;
                ans+=(po*no);
            }
            else{
                int nz=zeros-pz;
                ans+=(pz*nz);
            }
            po+=(s[i]=='1');
            pz+=(s[i]=='0');
        }
        return ans;
    }
};