class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        bool vis[n];
        memset(vis,false,sizeof(vis));
        queue<int> q;
        q.push(start);
        int jmps=0;
        vis[start]=true;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                int idx=q.front();
                q.pop();
                if(arr[idx]==0)
                    return true;
                if(idx-arr[idx]>=0){
                    if(!vis[idx-arr[idx]]){
                        vis[idx-arr[idx]]=true;
                        q.push(idx-arr[idx]);
                    }
                }
                if(idx+arr[idx]<arr.size()){
                    if(!vis[idx+arr[idx]]){
                        vis[idx+arr[idx]]=true;
                        q.push(idx+arr[idx]);
                    }
                }
            }
            jmps++;
        }
        return false;
    }
};