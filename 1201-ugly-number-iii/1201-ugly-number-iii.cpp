class Solution {
public:
    long gcd(long a,long b){
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    long lcm(long a,long b){
        return (a*b)/gcd(a,b);
    }
    int nthUglyNumber(int n,long a,long b,long c) {
        int s=0,e=2*1e9;
        int ans;
        while(s<e)
        {
            long m=(s+(e-s)/2);
            long ab=lcm(a,b);
            long bc=lcm(b,c);
            long ca=lcm(c,a);
            long abc=lcm(a,bc);
            long cnt=(m/a)+(m/b)+(m/c)-(m/ab)-(m/bc)-(m/ca)+(m/abc);
            if(cnt<n)
            {
                //cnt of numbers is less than n, we need to make s=m+1;
             //   ans=m;
                s=m+1;
            }
            else e=m;
        }
        return s;
    }
};