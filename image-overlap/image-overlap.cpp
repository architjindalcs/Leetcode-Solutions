class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<vector<int>> vv1,vv2;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(img1[i][j]) vv1.push_back({i,j});
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(img2[i][j]) vv2.push_back({i,j});
        
        unordered_map<string,int> m;
        for(vector<int>& v1: vv1){
            for(vector<int>& v2: vv2){
                int tx=v1[0]-v2[0],ty=v1[1]-v2[1];
                string tmp=to_string(tx)+"#"+to_string(ty);
                m[tmp]++;
            }
        }
        int ans=0;
        for(auto x: m) ans=max(ans,x.second);
        return ans;
    }
};