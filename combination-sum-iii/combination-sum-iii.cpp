class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& path,int cs,int sum,int siz){
        if(siz==path.size()){
            if(cs==sum)
                ans.push_back(path);
            return;
        }
        for(int i=(path.size()? path.back()+1: 1);i<=9;i++){
            if(cs+i<=sum){
                path.push_back(i);
                helper(path,cs+i,sum,siz);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        helper(path,0,n,k);
        return ans;
    }
};