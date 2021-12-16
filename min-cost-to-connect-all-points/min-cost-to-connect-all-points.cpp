class Solution {
public:
    int minDist(vector<bool>& inMST,vector<int>& dist){
        int minm=INT_MAX,idx=-1;;
        for(int i=0;i<inMST.size();i++){
            if(!inMST[i]){
                if(dist[i]<minm){
                    minm=dist[i];
                    idx=i;
                }
            }
        }
        return idx;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> adj(n,vector<int>(n));;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(i==j) continue;
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i][j]=adj[j][i]=dist;
            }
        }
        
        vector<int> dist(n,INT_MAX);
        vector<bool> inMST(n,false);
        dist[0]=0;
        vector<int> parent(n,-1);
        for(int i=0;i<n-1;i++){
            int u=minDist(inMST,dist);
            inMST[u]=true;  //already included in MST>.
            for(int v=0;v<n;v++){
                if(adj[u][v]!=INT_MAX and !inMST[v] and dist[v]>adj[u][v]){
                    dist[v]=adj[u][v];
                    parent[v]=u;
                }
            }
        }
        int cost=0;
        int tmp=n-1;
        for(int i=1;i<n;i++){
            cost+=adj[i][parent[i]];
        }
        return cost;
        //prims algorithm..
    }
};