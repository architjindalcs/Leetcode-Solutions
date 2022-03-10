class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>& v1,vector<int>& v2){
           return v1[0]<v2[0];
        });
        int pst=intervals[0][0],pend=intervals[0][1];
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int cst=intervals[i][0],cend=intervals[i][1];
            if(cst>pend){
                ans.push_back(intervals[i]);
                pst=cst;
                pend=cend;
            }
            else{
                if(cend<=pend){
                    //let it be..
                }
                else{
                    //cend>pend...
                    ans.pop_back();
                    ans.push_back({pst,cend});
                    pend=cend;
                }
            }
        }
        return ans;
    }
};