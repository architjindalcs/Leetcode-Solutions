class Solution {
public:
    vector<int> ans;
      int* helper(vector<int> adj[],int src,int par,string& labels){
          //this one only..
        int ch=labels[src]-'a';
        
        int ret[26];
          memset(ret,0,sizeof(ret));
       // vector<int> ret(26,0);  //ret consists of all the chars free in the current tree.
        
        ret[ch]=1;
        
        for(int ele: adj[src]){
            if(ele==par) continue;
            int* next=helper(adj,ele,src,labels);
            for(int i=0;i<26;i++) ret[i]+=next[i];
        }
        
        ans[src]+=ret[ch];
        return ret;
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
       // int n=labels.size();
        ans=vector<int> (n,0);
        vector<int> adj[n];
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        helper(adj,0,-1,labels);
        return ans;
    }
};