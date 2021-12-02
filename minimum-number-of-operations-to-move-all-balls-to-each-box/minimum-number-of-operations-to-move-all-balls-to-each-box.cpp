class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans(n,0);
        int cnt=(boxes[0]=='1');
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+cnt;
            cnt+=(boxes[i]=='1');
        }
        int next=0;
        cnt=(boxes[n-1]=='1');
        for(int i=n-2;i>=0;i--){
            ans[i]+=next+cnt;
            next+=cnt;
            cnt+=(boxes[i]=='1');
        }
        return ans;
    }
};