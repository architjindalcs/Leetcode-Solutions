class Solution {
public:
    bool checkPowersOfThree(int n) {
        // 7  2
        /*
          12 -> 110 (base 3)
          
          14 -> 112  (2*3^0 + 1*3^1 or 1*3^2)
         */
        while(n){
            int last=n%3;
            if(last==2) return false;
            n/=3;
        }
        return n<=1;
    }
};