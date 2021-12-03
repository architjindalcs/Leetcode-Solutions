class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=arr.size();
        int pre[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++) pre[i]=arr[i] xor pre[i-1];
        for(vector<int>& v: queries){
            int st=v[0],end=v[1];
            ans.push_back(pre[end] xor (st? pre[st-1]: 0));
        }
        return ans;
    }
};