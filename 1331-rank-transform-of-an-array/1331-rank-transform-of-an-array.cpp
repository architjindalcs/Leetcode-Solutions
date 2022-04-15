class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> rks;
        int i=0,rank=1;
        while(i<temp.size()){
            int ele=temp[i];
            while(i<temp.size() and temp[i]==ele) {
                i++;
            }
            rks[ele]=rank++;
        }
        for(int ele: arr) ans.push_back(rks[ele]);
        return ans;
    }
};