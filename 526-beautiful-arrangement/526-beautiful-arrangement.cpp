class Solution {
public:
    int cnt=0;
    vector<bool> used;
    void helper(int idx,int n){
        if(idx==n+1){
            cnt++;
            return;
        }
        
        for(int i=1;i<=n;i++){
            if(!used[i]){
                if(i%idx==0 or idx%i==0){
                    used[i]=true;
                    helper(idx+1,n);
                    used[i]=false;
                }
            }
        }
    }
    int countArrangement(int n) {
        used=vector<bool>(n+1,false);
        helper(1,n);
        return cnt;
    }
};