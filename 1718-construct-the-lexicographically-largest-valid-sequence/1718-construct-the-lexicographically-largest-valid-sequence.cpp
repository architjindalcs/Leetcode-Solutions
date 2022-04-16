class Solution {
public:
    vector<int> ans;
    vector<bool> used;
    bool helper(int idx){
        if(idx==ans.size()) return true;
    
        if(ans[idx]!=-1) return helper(idx+1);  //already placed a number here..
        for(int num=used.size()-1;num>=1;num--){
            if(!used[num]){
                //i can used it here..
                if(num==1){
                    used[num]=true;
                    ans[idx]=num;
                    if(helper(idx+1)) return true;
                    used[num]=false;
                    ans[idx]=-1;
                    continue;
                }
                int jidx=idx+num;
                if(jidx<ans.size() and ans[jidx]==-1){
                    used[num]=true;
                    ans[idx]=num;
                    ans[jidx]=num;
                    if(helper(idx+1)) return true;
                    ans[jidx]=-1;
                    ans[idx]=-1;
                    used[num]=false;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int siz=2*n-1;
        ans=vector<int> (siz,-1);
        used=vector<bool> (n+1,false);  //1 to n 
        helper(0);
        return ans;
    }
};