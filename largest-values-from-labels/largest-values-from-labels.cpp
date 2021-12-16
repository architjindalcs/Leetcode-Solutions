class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int ans=0;
        vector<pair<int,int> > v;
        for(int i=0;i<values.size();i++){
            v.push_back({values[i],labels[i]});
        }
        int siz=0;
        unordered_map<int,int> f;
        sort(v.begin(),v.end(),[&](pair<int,int>& p1,pair<int,int>& p2){
           return p1.first>p2.first; 
        });
        for(int i=0;i<v.size() and siz<numWanted;i++){
            int val=v[i].first;
            int lab=v[i].second;
            if(siz<numWanted and f[lab]<useLimit){
                ans+=val;
                siz++;
                f[lab]++;
            }
        }
        return ans;
    }
};