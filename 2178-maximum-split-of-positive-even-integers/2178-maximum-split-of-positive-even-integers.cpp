class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        if(finalSum%2) return {};
        vector<long long> ans;
        long long cs=0,i=2;
        while(cs+i<=finalSum){
            ans.push_back(i);
            cs+=i;
            i+=2;
        }
        //2,4,6,16  -> 20 28-20 = 8 -> 
        int sz=ans.size();
        ans[sz-1]+=(finalSum-cs);
        return ans;
    }
};