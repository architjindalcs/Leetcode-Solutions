class Solution {
public:
    vector<int> color;
    bool dfs(vector<vector<int>>& adj,int src){
        color[src]=2; //marked initially as unsafe..
        for(int i: adj[src]){
            if(color[i]==2) return false; //bychance, we get here..it will lead to cycle, so 
            //unsafe... 
            /*
                1--->2--->3
                ^
                |_ _ _ _ _|
                in above case, 1 is eventually unsafe node..
            */
            if(color[i]==0){
                if(!dfs(adj,i)){
                    return false;  //it is unsafe node...
                }
            }
        }
        color[src]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        color=vector<int> (n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(color[i]==0){
                if(dfs(adj,i)) ans.push_back(i);
            }
            else if(color[i]==1) ans.push_back(i);
        }
        return ans;
    }
};