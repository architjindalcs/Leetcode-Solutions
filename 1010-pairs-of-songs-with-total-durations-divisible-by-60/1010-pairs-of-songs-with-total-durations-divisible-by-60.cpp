class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int hash[60];
        memset(hash,0,sizeof(hash));
        for(int t: time) hash[t%60]++;
        int l=1,r=59;
        int ans=0;
        while(l<r){
            ans+=(hash[l]*hash[r]);
            l++;
            r--;
        }
        if(l==r){
            ans+=(hash[l]*(hash[l]-1))/2;
        }
        ans+=(hash[0]*(hash[0]-1))/2;
        return ans;
    }
};