class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        /*
            1+2+3=6
            2+3+4=9
            3+4+5=12
            4+5+6=15
            5+6+7=18
            (x-1,x,x+1) -> 3x..
        */
        if(num%3) return {};
        long long k=num/3;
        return {k-1,k,k+1};
        
    }
};