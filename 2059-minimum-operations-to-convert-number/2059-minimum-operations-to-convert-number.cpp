class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        q.push(start);
        int level=0;
        bool vis[1001];
        memset(vis,false,sizeof(vis));
        vis[start]=true;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                int fr=q.front();
                q.pop();
                if(fr==goal) {
                    cout<<"hiii"<<endl;
                    return level;
                }
                for(int i: nums){
                    if(fr+i>1000 or fr+i<0){
                        if(fr+i==goal) {
                            cout<<"fr1: "<<fr<<endl;
                            cout<<"i: "<<i<<endl; 
                            return level+1;
                        }
                    }
                    else if(fr+i>=0 and fr+i<=1000){
                        if(!vis[fr+i]){
                            vis[fr+i]=true;
                            q.push(fr+i);
                        }
                    }
                    
                    if(fr-i>1000 or fr-i<0){
                        if(fr-i==goal) {
                            cout<<"fr2: "<<fr<<endl;
                            cout<<"i: "<<i<<endl; 
                            return level+1;
                        }
                    }
                    else if(fr-i>=0 and fr-i<=1000){
                        if(!vis[fr-i]){
                            vis[fr-i]=true;
                            q.push(fr-i);
                        }
                    }
                    
                    
                    if((fr^i)>1000 or (fr^i)<0){
                        if((fr^i)==goal) {
                            cout<<"fr3: "<<fr<<endl;
                            cout<<"i: "<<i<<endl; 
                            return level+1;
                        }
                    }
                    else if((fr^i)>=0 and (fr^i)<=1000){
                        if(!vis[fr^i]){
                            vis[fr^i]=true;
                            q.push(fr^i);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};