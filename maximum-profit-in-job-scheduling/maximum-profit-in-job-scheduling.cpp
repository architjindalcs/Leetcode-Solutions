class Job{
    public:
    int st,end,profit;
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> v;
        for(int i=0;i<profit.size();i++)
            v.push_back({startTime[i],endTime[i],profit[i]});
        int n=v.size();
        int dp[n];
        //sorted jobs on the basis of endtime..
        sort(v.begin(),v.end(),[&](Job& j1,Job& j2){
            return j1.end!=j2.end? j1.end<=j2.end: j1.profit<j2.profit;
        });
        dp[0]=v[0].profit;
        for(int i=1;i<v.size();i++){
            int stt=v[i].st,endt=v[i].end,profit=v[i].profit;
            dp[i]=max(v[i].profit,dp[i-1]); //I am not chosing this job..
            int idx=-1;
            int st=0,end=i-1;
            while(st<=end){
                int mid=(st+end)/2;
                if(v[mid].end<=stt){
                    idx=mid;
                    st=mid+1;
                }
                else
                    end=mid-1;
            }
            if(idx!=-1)
                dp[i]=max(dp[i],profit+dp[idx]);
        }
        return dp[n-1];
    }
};