class Solution {
public:
    int helper(int n,int k){
        if(n==1) return 0; //single hi aadmi bacha h na...
        int next=helper(n-1,k);
        return (next+k)%n;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;
    }
};