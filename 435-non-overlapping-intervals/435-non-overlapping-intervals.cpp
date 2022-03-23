class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>& v1,vector<int>& v2){
            return v1[1]<v2[1];      
        });
        int pend=intervals[0][1];
        
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            int cst=intervals[i][0],cend=intervals[i][1];
            if(cst>=pend){
                pend=cend;
                continue;
            }
            ans++;
        }
        return ans;
    } 
};