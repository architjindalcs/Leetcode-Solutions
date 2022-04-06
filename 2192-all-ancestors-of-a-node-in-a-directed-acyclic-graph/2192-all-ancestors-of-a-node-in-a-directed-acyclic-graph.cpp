class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int indeg[n];
        memset(indeg,0,sizeof(indeg));
        vector<int> adj[n];
        for(vector<int>& e: edges){
            indeg[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        vector<set<int> > ans(n);
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(q.size()){
            int fr=q.front();
            q.pop();
            for(int j: adj[fr]){
                indeg[j]--;
                ans[j].insert(fr);
                for(int ele: ans[fr]) ans[j].insert(ele);
                if(indeg[j]==0) q.push(j);
            }
        }
        vector<vector<int>> ret;
        for(set<int>& st: ans)
            ret.push_back(vector<int>(st.begin(),st.end()));
        
        return ret;
    }
};