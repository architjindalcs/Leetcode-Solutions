class Solution {
public:
    vector<int> dp;
    int ans=0;
    int helper(vector<int> adj[],string& s,int src){
       
        int maxm=0,smaxm=0;
        for(int i: adj[src]){
            if(s[i]!=s[src]){
                int nans=helper(adj,s,i);
                if(nans>=maxm){
                    smaxm=maxm;
                    maxm=nans;
                }
                else if(nans>=smaxm){
                    smaxm=nans;
                }
            }
            else ans=max(ans,helper(adj,s,i));
        }
        ans=max(ans,1+maxm+smaxm);
        return 1+max(maxm,smaxm);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<int> adj[n];
        dp=vector<int> (n,-1);
        for(int i=0;i<parent.size();i++){
            if(parent[i]!=-1){
                adj[parent[i]].push_back(i);
            }
        }
        int k=helper(adj,s,0);
        return ans;
    }
};