class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i: arr) m[i]++;
        vector<int> v;
        for(auto x: m) v.push_back(x.second);
        sort(v.begin(),v.end());
        int cnt=0,ans=0,idx=0;
        while(idx<v.size()){
            cnt+=v[idx];
            idx++;
            if(cnt<=k)
            ans++;
            else return v.size()-ans;
        }
        return v.size()-ans;
    }
};