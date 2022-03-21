class Solution {
public:
    bool divisorGame(int n) {
        /*
            n=1  choose b/w 0<x<1 -> no number Alice lose
            n=2             0<x<2 -> 1 -> n=1 for Bob, Alice wins..
            n=3 choose 1 -> (n=2) -> Alice loses..
            n=4 , choose 1, n=3 (bob loses) -> alice wins
            n=5, choose 1 -> n=4 (alice loses) -> bob wins
            n=6 , choose 1 -> n=5 (bob loses) -> alice wins.
            n-7, bob
            n=8 -> alice
            n=9 , 
         
        */
        return n%2==0;
    }
};