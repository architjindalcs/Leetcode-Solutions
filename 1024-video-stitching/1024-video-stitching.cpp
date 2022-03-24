class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int to_start_from=0,ending_at=0;
        int ans=0;
        while(ending_at<time){
            for(vector<int>& c: clips){
                int st=c[0],end=c[1];
                if(st<=to_start_from){
                    ending_at=max(ending_at,end);
                }
            }
            //now ending_at will have the maxm ending interval time satisfying
            if(to_start_from==ending_at) return -1;
            ans++;
            to_start_from=ending_at;
        }
        return ans;
    }
};