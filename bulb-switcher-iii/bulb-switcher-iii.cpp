class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int maxm=0,cnt=0;
        for(int i=0;i<light.size();i++){
            maxm=max(maxm,light[i]);
            if(maxm==i+1) cnt++;
        }
        return cnt;
    }
};