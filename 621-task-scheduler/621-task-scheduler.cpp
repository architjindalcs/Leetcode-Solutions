class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char,int> m;
        for(char ch: tasks) m[ch]++;
        for(auto& x: m) pq.push(x.second);
        
        int ans=0;
        while(pq.size()){
            vector<int> temp;
            int time=0;
            for(int i=0;i<n+1;i++){
                if(pq.size()){
                    int tp=pq.top();
                    pq.pop();
                    time++;
                    if(tp-1) temp.push_back(tp-1);
                }
            }
            if(temp.size()){
                for(int i: temp) pq.push(i);
                ans+=(n+1);
            }
            else ans+=time;
        }
        return ans;
    }
};