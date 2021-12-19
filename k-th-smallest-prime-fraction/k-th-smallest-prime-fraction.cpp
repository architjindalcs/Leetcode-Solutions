class Pair{
    public:
    int first;
    int second;
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp=[&](Pair& p1,Pair& p2){
            int num1=arr[p1.first],den1=arr[p1.second];
            int num2=arr[p2.first],den2=arr[p2.second];
            return num1*den2>den1*num2;
        };
        priority_queue<Pair,vector<Pair>,decltype(cmp)> pq(cmp);
        int n=arr.size();
        for(int i=0;i<n-1;i++) pq.push({i,n-1});
        int cnt=0;
        while(pq.size()){
            int nidx=pq.top().first,didx=pq.top().second;
            pq.pop();
            cnt++;
            if(cnt==k) return {arr[nidx],arr[didx]};
            if(didx-1>nidx){
                pq.push({nidx,didx-1});
            }
        }
        return {};
    }
};