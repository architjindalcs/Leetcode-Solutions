class Solution {
public:
    bool isPowerOfTwo(long n) {
        if(n==0) return false;
        return !(n&(n-1));
    }
};