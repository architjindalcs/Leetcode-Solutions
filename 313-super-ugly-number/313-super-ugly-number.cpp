class pairr{
    public:
    long val,prime,idx;
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
     //   sort(primes.begin(),primes.end()); 
        if(n==1) return 1;
        int cnt=1; 
        auto cmp=[](pairr& p1,pairr& p2){
            return p1.val>p2.val;
        };
        priority_queue<pairr,vector<pairr>,decltype(cmp)> pq(cmp);
        //vector<int> nI(primes.size(),1);
        int last=1;
        for(int i=0;i<primes.size();i++) pq.push({primes[i],primes[i],0});
        
        vector<long> dp(n);
        dp[0]=1;
        while(cnt<n){
            pairr tp=pq.top();
            pq.pop();
            int value=tp.val,prime=tp.prime,dpidx=tp.idx;
            if(value!=dp[cnt-1]){
                dp[cnt]=value;
                cnt++;
                
            }
            
           pq.push({(long)prime*dp[dpidx],prime,dpidx+1});
        }
        return dp[n-1];
    }
};