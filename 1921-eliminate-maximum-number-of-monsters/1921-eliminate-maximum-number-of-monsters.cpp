class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> v;
        for(int i=0;i<dist.size();i++){
            v.push_back(dist[i]/(1.0*speed[i]));
        }
        sort(v.begin(),v.end());
        int nextAvl=0;
        int ans=0;
        for(int i=0;i<v.size();i++){
           // cout<<"v[i]: "<<v[i]<<endl;
            if(v[i]>nextAvl) {
                ans++;
                nextAvl++;
            }
            else return ans;
        }
        return ans;
    }
};