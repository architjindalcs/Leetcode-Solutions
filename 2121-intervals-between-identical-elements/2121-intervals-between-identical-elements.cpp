class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++) m[arr[i]].push_back(i);
        //1,2,5,7,12,20
        //
        vector<long long> ret(arr.size(),0);
        for(auto& x: m){
            long long sum=0;
            for(int i: x.second) sum+=(long long)i; //sum of whole array..
            long long psum=0;
            long long dummyIdx=0;
            for(long long num: x.second){
                long long ans=sum-(x.second.size()-dummyIdx)*num;
                ans+=(dummyIdx*num-psum);
                psum+=(num);
                sum-=(num);
                ret[num]=ans;
                dummyIdx++;
            }
        }
        return ret;
    }
};