class Solution {
public:
    bool safe(vector<vector<int>>& adj,int src,vector<int>& color){
        /*
            color[i] = -1, unvisited
            color[i] = 0, eventually safe
            color[i] = 1, unsafe state
        */
        color[src]=1;  //marking it as unsafe for the time being..
        for(int i: adj[src]){
            if(color[i]==1) return false;  //it is not safe state, because leading to cycle eventually ...
            if(color[i]==-1){
                //not visited node..
                if(!safe(adj,i,color)){
                    return false;
                }
            }
        }
        color[src]=0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(safe(graph,i,color))
                ans.push_back(i);    
            }
            else if(color[i]==0) ans.push_back(i);
        }
        return ans;
    }
};