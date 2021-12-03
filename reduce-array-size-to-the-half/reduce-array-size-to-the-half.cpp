class Solution {
public:
    int minSetSize(vector<int>& arr) {
       unordered_map<int,int> m;
        for(int i: arr) m[i]++;
        vector<int> v;
        for(auto x: m) v.push_back(x.second);
        sort(v.begin(),v.end(),greater<int>());
        int ans=0,cnt=0;
        for(int i: v){
            cnt+=(i);
            ans++;
            if(cnt>=(arr.size()/2)) return ans;
        }
        return ans;
    }
};