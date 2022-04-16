class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    bool Union(int x,int y){
        int xrep=find(x),yrep=find(y);
        if(xrep==yrep) return false;  //same components ka part h
        if(rank[xrep]<=rank[yrep]){
            parent[xrep]=yrep;
            rank[yrep]+=rank[xrep];
        }
        else{
            parent[yrep]=xrep;
            rank[xrep]+=rank[yrep];
        }
        return true;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables=connections.size();
        if(cables<n-1) return -1;  //to connect n vertices, we require at least n-1 cables..
        parent=vector<int> (n,-1);
        rank=vector<int> (n,1);
        int cc=n;
        for(vector<int>& c: connections){
            if(Union(c[0],c[1])) cc--;
        }
        return cc-1;
        
    }
};