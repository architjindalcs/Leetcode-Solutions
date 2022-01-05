class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int st=newInterval[0],end=newInterval[1];
        int i=0;
        vector<vector<int>> ans;
        while(i<intervals.size() and intervals[i][1]<st) {
            ans.push_back(intervals[i++]);
        }
        
        while(i<intervals.size() and (intervals[i][0]<=end)){
            st=min(st,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i++;
        }
        ans.push_back({st,end});
        while(i<intervals.size()){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
    
};