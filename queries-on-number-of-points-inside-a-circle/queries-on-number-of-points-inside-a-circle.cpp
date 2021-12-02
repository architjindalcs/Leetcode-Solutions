class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(vector<int> v: queries){
            int cnt=0;
            int x=v[0],y=v[1],r=v[2];
            for(vector<int> p: points){
                int v1=p[0]-x,v2=p[1]-y;
                if(v1*v1+v2*v2-r*r<=0) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};