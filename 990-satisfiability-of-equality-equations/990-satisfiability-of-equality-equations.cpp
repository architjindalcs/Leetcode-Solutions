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
        if(xrep==yrep) return false;
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
    bool equationsPossible(vector<string>& equations) {
        parent=vector<int> (26,-1);
        rank=vector<int> (26,1);
        for(string& s: equations){
            if(s[1]=='='){
                Union(s[0]-'a',s.back()-'a');
            }
        }
        for(string& s: equations){
            if(s[1]=='!'){
                int xrep=find(s[0]-'a');
                int yrep=find(s.back()-'a');
                if(xrep==yrep) return false;
            }
        }
        return true;
    }
};