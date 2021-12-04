class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(),points.begin()+k-1,points.end(),[&](vector<int>& pt1,vector<int>& pt2){
            int d1=pt1[0]*pt1[0]+pt1[1]*pt1[1];
            int d2=pt2[0]*pt2[0]+pt2[1]*pt2[1];
            return d1<d2;
        });
        vector<vector<int>> ans;
        for(int i=0;i<=k-1;i++) ans.push_back(points[i]);
        return ans;
    }
};