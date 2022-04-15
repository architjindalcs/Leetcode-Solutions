class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cmp=[&](int n11,int n22){
            int n1=n11,n2=n22;
            int cnt1=0;
            while(n1){
                cnt1++;
                n1=n1&(n1-1);
            }
            int cnt2=0;
            while(n2){
                cnt2++;
                n2=n2&(n2-1);
            }
            return cnt1==cnt2? n11<n22 : cnt1<cnt2;
        };
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};