class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int i=0,ans=0;
        while(i<colors.size()){
            char ch=colors[i];
            int maxm=INT_MIN,cnt=0,sum=0;
            while(i<colors.size() and colors[i]==ch){
                maxm=max(maxm,neededTime[i]);
                sum+=neededTime[i];
                cnt++;
                i++;
            }
            if(cnt>1){
                ans+=(sum-maxm);
            }
        }
        return ans;
    }
};