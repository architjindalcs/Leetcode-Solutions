class Solution {
public:
    int minFlips(string target) {
        int flip=0;
        int ans=0;
        for(int i=0;i<target.size();i++){
            int cbit=(flip ? 1 : 0);
            int rbit=(target[i]-'0');
            if(rbit==cbit) continue;
            flip=1-flip;
            ans++;
        }
        return ans;
    }
};