class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_set<int> st;
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                for(int k=0;k<digits.size();k++){
                    if(i==j or i==k or j==k) continue;
                    if(digits[i]==0 or digits[k]&1) continue;
                    int num=digits[i]*100+digits[j]*10+digits[k];
                    //546
                    st.insert(num);
                }
            }
        }
        ans=vector<int> (st.begin(),st.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};