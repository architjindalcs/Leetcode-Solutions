class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int map[n*n+1];
        memset(map,-1,sizeof(map));
        int num=1;
        bool f=true;
        for(int i=n-1;i>=0;i--){
            if(f){
                for(int j=0;j<n;j++){
                    if(board[i][j]!=-1){
                        map[num]=board[i][j];
                    }
                    num++;
                }        
            }
            else{
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]!=-1){
                        map[num]=board[i][j];
                    }
                    num++;
                }
            }
            f=!f;
        }
        bool vis[n*n+1];
        memset(vis,false,sizeof(vis));
        queue<int> q;
        q.push(1);
        vis[1]=true;
        int level=0;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                int fr=q.front();
                q.pop();
                if(fr>=n*n) return level;
                for(int di=1;di<=6;di++){
                    if(fr+di<=n*n){
                        int nval=fr+di;
                        if(map[nval]!=-1) nval=map[nval];
                        if(!vis[nval]){
                            vis[nval]=true;
                            q.push(nval);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};