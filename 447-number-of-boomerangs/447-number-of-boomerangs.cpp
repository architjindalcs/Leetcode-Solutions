class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<points.size();i++){
            m.clear();
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int d2=(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                d2+=(points[i][0]-points[j][0])*(points[i][0]-points[j][0]);
                m[d2]++;
            }
            for(auto x: m){
                int f=x.second;
                ans+=(f*(f-1));
            }
        }
        return ans;
    }
};