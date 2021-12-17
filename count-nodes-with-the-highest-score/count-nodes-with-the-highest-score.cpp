class Solution {
public:
    unordered_map<int,int> smap;
    int size(vector<int> adj[],int src){
        int ans=0;
        for(int i: adj[src]){
            ans+=size(adj,i);
        }
        return smap[src]=1+ans;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<int> adj[n];
        int root=-1;
        for(int i=0;i<parents.size();i++){
            if(parents[i]==-1) root=i;
            else adj[parents[i]].push_back(i);
        }
        size(adj,root);
        long long maxm=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            long long pro=1;
            if(parents[i]!=-1){
                pro*=((long long)smap[root]-smap[i]);
            }
            for(int child: adj[i]) {
                pro*=((long long)smap[child]);
            }
            if(pro>maxm){
                maxm=pro;
                cnt=1;
            }
            else if(pro==maxm) cnt++;
            //maxm=max(maxm,pro);
        }
        return cnt;
    }
};