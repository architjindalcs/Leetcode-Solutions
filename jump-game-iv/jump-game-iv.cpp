class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<int> q;
        int n=arr.size();
        vector<bool> vis(n,false);
        q.push(0);
        vis[0]=true;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++) m[arr[i]].push_back(i);
        int jmps=0;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                int fr=q.front();
                q.pop();
                if(fr==n-1) return jmps;
                int i=fr;
                if(i+1<arr.size() and !vis[i+1]){
                    vis[i+1]=true;
                    q.push(i+1);
                }
                if(i-1>=0 and !vis[i-1]){
                    vis[i-1]=true;
                    q.push(i-1);
                }
                for(int j: m[arr[fr]]){
                    if(!vis[j]){
                        vis[j]=true;
                        q.push(j);
                    }
                }
                if(m.count(arr[fr])) m.erase(arr[fr]);
            }
            jmps++;
        }
        return -1;
    }
};