class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long wt=customers[0][1]; //for the first customer, order starts preparing as soon as, it gets the request, as it is the first customer itslef..
        long long nextStart=customers[0][0]+customers[0][1];
        for(int i=1;i<customers.size();i++){
            long long arr=customers[i][0],time=customers[i][1];
            wt+=(max((long long)0,nextStart-arr)+time);
            nextStart=(max(arr,nextStart)+time);
        }
        return (wt*1.0/(customers.size()));
    }
};