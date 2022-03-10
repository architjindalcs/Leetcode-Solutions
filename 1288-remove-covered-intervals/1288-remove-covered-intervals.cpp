class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>& v1,vector<int>& v2){
            return v1[0]!=v2[0]? v1[0]<v2[0]: v1[1]>v2[1]; 
        });
        int minm=intervals[0][0],maxm=intervals[0][1];
        int ans=intervals.size();
        
        for(int i=1;i<intervals.size();i++){
            int st=intervals[i][0],end=intervals[i][1];
            if(st>=minm and end<=maxm){
                //this one is covered...
                ans--;  
            }
            else maxm=max(maxm,end);
        }
        return ans;
    }
};