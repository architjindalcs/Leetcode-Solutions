class Solution {
public:
    int twoEggDrop(int n) {
        //x+(x-1)+(x-2)  ......1 x(x+1)=2n -> x^2+x-2n=0  x= (-1+-sqrt(1+8n))/2
        
        return ceil((-1+sqrt(1+8*n))/2);
    }
};