class Solution {
public:
    int getSum(int a, int b) {
        
        while(b){
            long c=a&b;
            a=a xor b;
            b=(c*2);
        }
        return a;
    }
};