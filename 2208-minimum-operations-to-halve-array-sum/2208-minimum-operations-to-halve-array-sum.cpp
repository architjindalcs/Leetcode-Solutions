class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        multiset<double> st;
        for(int i: nums) {
            sum+=i;
            st.insert(i*1.0);
        }
        double actualSum=sum;
        int ans=0;
        while(sum>actualSum/2){
            double maxm=*(st.rbegin());
            st.erase(st.find(maxm));
            sum-=(maxm/2.0);
            ans++;
            st.insert(maxm/2.0);
        }
        return ans;
    }
};