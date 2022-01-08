class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long tsum=0;
        for(int i: grid[0]) tsum+=(long long)i;
        long long tpsum=0;
        long long bpsum=0;
        
        long long minm=LONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            //I switch on the ith index...
            tpsum+=((long long)grid[0][i]);
            long long rob2=tsum-tpsum;
            rob2=max(rob2,bpsum);
            bpsum+=((long long)grid[1][i]);
            minm=min(minm,rob2);
           // cout<<"rob2: "<<rob2<<endl;
        }
        minm=min(minm,bpsum);
        return minm;
    }
};