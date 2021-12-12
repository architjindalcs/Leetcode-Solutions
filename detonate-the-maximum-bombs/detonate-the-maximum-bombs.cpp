class Solution {
public:
    
    void helper(vector<vector<int>>& bombs,vector<bool>& vis,int idx,int& cnt){
        cnt++;
        vis[idx]=true; //detonated the bomb..
        for(int i=0;i<bombs.size();i++){
            if(vis[i]) continue; //already diffused..
            long long cx=(long long)bombs[i][0],cy=(long long)bombs[i][1];
            long long v1=(long long)abs(cx-bombs[idx][0]),v2=(long long)abs(cy-bombs[idx][1]);
            long long r=(long long)bombs[idx][2];
            if(v1*v1+v2*v2-r*r<=0){
                //andar h 
                helper(bombs,vis,i,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans=0;
        for(int i=0;i<bombs.size();i++){
            int cnt=0;
            vector<bool> vis(bombs.size(),false);
            helper(bombs,vis,i,cnt);
            ans=max(ans,cnt);
        }
        return ans;
    }
};