class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum=0;
        for(int i: nums) sum+=i;
        long req=goal-sum;
        if(!req) return 0;
        req=abs(req);
            //lim=3 
        if(req%limit==0) return req/limit;
        return (req/limit)+1;
    }
};