class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool> ans;
        bool adj[n][n];
        memset(adj,false,sizeof(adj));
        for(vector<int>& v: pre){
            adj[v[0]][v[1]]=true;  
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==k or j==k) continue;;
                    adj[i][j]=(adj[i][j] or (adj[i][k] and adj[k][j]));
                }
            }
        }
        for(vector<int>& q: queries){
            int st=q[0],end=q[1];
            ans.push_back(adj[st][end]);
        }
        return ans;
    }
};