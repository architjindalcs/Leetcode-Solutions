class Solution {
public:

    bool cycle(vector<int> adj[],int src,vector<bool>& vis,vector<bool>& inStack){
        vis[src]=true;
        inStack[src]=true;
        for(int i: adj[src]){
            if(inStack[i]) return true;
            else if(!vis[i] and cycle(adj,i,vis,inStack)) return true;
        }
        inStack[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(vector<int>& p: pre){
            int st=p[1],end=p[0];
            adj[st].push_back(end);
        }
        vector<bool> inStack(n,false);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]) if(cycle(adj,i,vis,inStack)) return false;
        }
        for(bool b: vis) if(!b) return false;
        return true;
    }
};