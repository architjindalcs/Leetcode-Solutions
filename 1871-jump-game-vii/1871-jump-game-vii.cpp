class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back()=='1') return false;
        int n=s.size();
        bool dp[n];
        memset(dp,0,sizeof(dp));
        //index=4  minJump=2, 0 index-minJump-1 , out of window.. 
    // index 4, minjmp=2,maxjmp=4,  either 1 or 2..
        //index 6-> 2->6, 3->6, 4->6
        dp[0]=true;  
        int prev=0; //prev positions we can jump from to the current index..
        for(int i=1;i<n;i++){
            if(i-maxJump-1>=0) prev-=(dp[i-maxJump-1]);
            if(i-minJump>=0) prev+=(dp[i-minJump]); //new index added to window..
            if(prev and s[i]=='0') dp[i]=true;
        }
        return dp[n-1];
    }
};