class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long rev=0;
        int temp=x;
        while(x){
            rev=rev*10+(x%10);
            x/=10;
        }
        return rev==(long)temp;
    }
};