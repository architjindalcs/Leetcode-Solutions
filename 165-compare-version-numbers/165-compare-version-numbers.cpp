class Solution {
public:
    int compareVersion(string s1, string s2) {
        s1+=".";
        s2+=".";
        int i=0,j=0;
        while(i<s1.size() or j<s2.size()){
            int val1=0,val2=0;
            while(i<s1.size() and s1[i]!='.'){
                val1=val1*10+(s1[i]-'0');
                i++;
            }
            while(j<s2.size() and s2[j]!='.'){
                val2=val2*10+(s2[j]-'0');
                j++;
            }
            i++;
            j++;
            if(val1>val2) return 1;
            else if(val1<val2) return -1;
        }
        return 0;
    }
};