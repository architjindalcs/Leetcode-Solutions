class Solution {
public:
    vector<int> color;
    
    bool helper(vector<int> adj[],int src){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                int fr=q.front();
                q.pop();
                for(int i: adj[fr]){
                    if(color[i]==color[fr]) return false;
                    else if(color[i]==-1){
                        color[i]=1-color[fr];
                        q.push(i);
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        for(vector<int>& d: dislikes){
            adj[d[0]-1].push_back(d[1]-1);
            adj[d[1]-1].push_back(d[0]-1);
        }
        color=vector<int> (n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!helper(adj,i)) return false;
            }
        }
        return true;
    }
};