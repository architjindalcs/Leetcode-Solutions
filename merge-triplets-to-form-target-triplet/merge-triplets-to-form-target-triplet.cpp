class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> v(3,0);
        for(vector<int>& t: triplets){
            if(t[0]<=target[0] and t[1]<=target[1] and t[2]<=target[2]){
                v[0]=max(v[0],t[0]); v[1]=max(v[1],t[1]); v[2]=max(v[2],t[2]);
            }
        }
        return v==target;
    }
};