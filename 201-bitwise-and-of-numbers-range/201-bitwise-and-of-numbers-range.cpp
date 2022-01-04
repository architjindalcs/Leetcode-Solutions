class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long mf=1;
        while(left!=right){
            left/=2;
            right/=2;
            mf*=2;
        }
        return left*mf;
    }
};