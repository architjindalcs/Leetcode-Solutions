class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> m;
        sort(arr.begin(),end(arr));
        for(int i: arr) m[i]++;
        for(int i: arr){
            if(!m[i]) continue;
            if(i<0 and i%2) return false;
            int ele=(i>0? 2*i: i/2);
            if(m[ele]==0) return false;
            m[ele]--;
            m[i]--;
        }
        return true;
    }
};