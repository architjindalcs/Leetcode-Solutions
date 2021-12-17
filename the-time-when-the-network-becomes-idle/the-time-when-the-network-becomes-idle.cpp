class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<int> adj[n];
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int siz=q.size();
            while(siz--){
                int fr=q.front();
                q.pop();
                for(int i: adj[fr]){
                    if(dist[i]>=dist[fr]+1){
                        dist[i]=dist[fr]+1;
                        q.push(i);
                    }
                }
            }
        }
        for(int i=0;i<n;i++) dist[i]*=2;
        int ans=0;
        for(int i=1;i<n;i++){
            int pat=patience[i],reply=dist[i];
            if(reply%pat==0){
                ans=max(ans,((reply/pat)-1)*pat+reply);
            }
            else{
                ans=max(ans,((reply/pat)*pat+reply));
            }
        }
        return ++ans;
    }
};