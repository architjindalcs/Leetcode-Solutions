class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        queue<pair<int,int> > q;
        for(int i=0;i<tickets.size();i++) q.push({tickets[i],i});
        while(q.size()){
            int tcount=q.front().first;
            int idx=q.front().second;
            q.pop();
            ans++;
            tcount--;
            if(tcount==0 and idx==k) return ans;
            if(tcount) q.push({tcount,idx});
        }
        
        return -1;
    }
};