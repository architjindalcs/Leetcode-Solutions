class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        if(a) pq.push(a); if(b) pq.push(b); if(c) pq.push(c);
        int ans=0;
        while(pq.size()>=2){
            int max1=pq.top();
            pq.pop();
            int max2=pq.top();
            pq.pop();
            ans++;
            if(--max1) pq.push(max1);
            if(--max2) pq.push(max2);
        }
        return ans;
    }
};