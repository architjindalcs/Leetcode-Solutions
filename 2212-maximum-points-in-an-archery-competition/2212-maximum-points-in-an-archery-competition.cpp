class Solution {
public:
    vector<int> ans;
    int maxPoints=0;
    
    void helper(vector<int>& aliceArrows,int left,vector<int>& bob,int idx){
        if(idx==-1){
            int cpoints=0;
            for(int i=0;i<bob.size();i++){
                if(bob[i]>aliceArrows[i]) cpoints+=(i);
            }
            if(cpoints>maxPoints){
                maxPoints=cpoints;
                ans=bob;
            }
            return;
        }
        if(left<=aliceArrows[idx]){
            //i won't waste arrows here..
            helper(aliceArrows,left,bob,idx-1);
            return;  
        }
        
        //now i can take a bet here..skip
        helper(aliceArrows,left,bob,idx-1);
    
        
        //use this slot..
        
        bob[idx]=aliceArrows[idx]+1;
        helper(aliceArrows,left-bob[idx],bob,idx-1);
        bob[idx]=0;
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12,0);
        helper(aliceArrows,numArrows,bob,11);
        int total=0;
        for(int i=0;i<ans.size();i++) total+=ans[i];
        
        int left=numArrows-total;
        ans[0]+=left;
        return ans;
    }
};