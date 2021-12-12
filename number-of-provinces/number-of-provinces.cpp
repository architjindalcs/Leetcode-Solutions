class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int cc;
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int xrep=find(x),yrep=find(y);
        if(xrep==yrep) return; //just return..
        cc--;
        if(rank[xrep]<=rank[yrep]){
            parent[xrep]=yrep;
            rank[yrep]+=rank[xrep];
        }
        else{
            parent[yrep]=xrep;
            rank[xrep]+=rank[yrep];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent=vector<int> (n,-1);
        rank=vector<int>(n,1);
        cc=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //if(i==j) continue;
                if(isConnected[i][j]) {
                    Union(i,j); 
                }
            }
        }
        return cc;
    }
};