class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>=2){
            int tp1=pq.top();
            pq.pop();
            int tp2=pq.top(); pq.pop();
            cout<<"tp1: "<<tp1<<endl;
            cout<<"tp2: "<<tp2<<endl;
            if(tp1==tp2) continue;
            else
            pq.push(abs(tp1-tp2));
        }
        return pq.empty()? 0 : pq.top();
    }
};