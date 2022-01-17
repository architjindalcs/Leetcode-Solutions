class Solution {
public:
    long long pow(long long a,long long n){
        //return a^n;
        long long ans=1;
        int mod=1000000007;
        while(n){
            int bit=n&1;
            if(bit)
                ans=((ans%mod)*(a%mod))%mod;
            n>>=1;
            a=(a%mod*(a%mod))%mod;
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long cntEve=(n+1)/2;
        long long cntOdd=(n/2);
        int mod=1000000007;
        long long val1=(pow(5,cntEve))%mod;
        long long val2=(pow(4,cntOdd))%mod;
        return (val1%mod*(val2%mod))%mod;
    }
};