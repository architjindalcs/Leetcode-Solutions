class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        for(int i=0;i<intervals.size();i++) intervals[i].push_back(i);
        sort(intervals.begin(),intervals.end(),[&](vector<int>& v1,vector<int>& v2){
           return v1[0]<v2[0]; 
        });  //sort by starting time..
        ans=vector<int> (intervals.size(),-1);
        for(vector<int>& v: intervals){
            int st=v[0],end=v[1],idx=v[2];
            int l=0,r=intervals.size()-1, ansIdx=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(intervals[mid][0]>=end){
                    ansIdx=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(ansIdx!=-1)
            ans[idx]=intervals[ansIdx].back();
        }
        return ans;
    }
};