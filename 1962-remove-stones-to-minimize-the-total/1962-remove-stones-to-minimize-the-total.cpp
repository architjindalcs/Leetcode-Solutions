class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int cnt=0;
        priority_queue<int> pq;
        for(int i: piles) pq.push(i);
        while(cnt<k and pq.size()){
            int tp=pq.top();
            pq.pop();
            tp=(tp-(tp/2));
            if(tp) pq.push(tp);
            cnt++;
        }
        int ans=0;
        while(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};