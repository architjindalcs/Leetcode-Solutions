class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> m;
        int idx=0;
        for(vector<int>& v: pieces) 
            m[v[0]]=idx++;
        int i=0;
        while(i<arr.size()){
            int id=m[arr[i]];
            int j=0;
            while(i<arr.size() and j<pieces[id].size()){
                if(arr[i]!=pieces[id][j])
                    break;
                i++;
                j++;
            }
            if(j!=pieces[id].size()) return false;
        }
        return i==arr.size();
    }
};