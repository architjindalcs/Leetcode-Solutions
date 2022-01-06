class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int i=0;
        bool go=true;
        while(i<num.size() and go){
            int dig=num[i]-'0';
            if(change[dig]<=dig){
                i++;
                continue;  //no need to change 
            }
            go=false;
            while(i<num.size()){
                int dig=num[i]-'0';
                if(change[dig]<dig) break;  //no more changes..
                num[i]=(change[dig]+'0');
                i++;
            }
        }
        return num;
    }
};