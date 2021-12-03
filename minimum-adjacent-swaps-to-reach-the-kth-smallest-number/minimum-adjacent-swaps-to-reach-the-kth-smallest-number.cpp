class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s1=num;
        while(k--) next_permutation(num.begin(),num.end());
        string s2=num;
        int i=0,j=0;
        int ans=0;

        while(i<s1.size()){
            if(s1[i]==s2[i]){
                i++;
            }
            int idx=i;
            while(s2[idx]!=s1[i]) {
                idx++;
            }
            while(idx>i){
                s2[idx]=s2[idx-1];
                idx--;
                ans++;
            }
            s2[idx]=s1[i];
        }
        return ans;
  
    }
};