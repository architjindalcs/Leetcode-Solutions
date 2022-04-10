class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1000000007;
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        while(k--){
            int tp=pq.top();
            pq.pop();
            tp++;
            pq.push(tp);
        }
        long ans=1;
       // int mod=1000000007;
        while(pq.size()){
            ans=(ans%mod*(pq.top()%mod))%mod;
            pq.pop();
        }
        return ans%mod;
    }
};