class Solution {
public:
    int maxm=0,siz;
    
    int getc(int a,int b){
        int score=0;
        for(int i=0;i<siz;i++){
            int b1=a&(1<<i);
            int b2=b&(1<<i);
            if(b1==b2) score++;
        }
        return score;
    }
    void helper(vector<int>& s,int curr,int idx,vector<int>& m,vector<bool>& used){
        if(idx==s.size()){
            maxm=max(maxm,curr);
            return;
        }
        
        for(int i=0;i<m.size();i++){
            if(!used[i]){
                used[i]=true;
                helper(s,curr+getc(s[idx],m[i]),idx+1,m,used);
                used[i]=false;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> s,m;
        siz=students[0].size();
        for(vector<int>& v: students){
            int sum=0;
            for(int i=v.size()-1;i>=0;i--){
                sum=sum*2+(v[i]);
            }
            s.push_back(sum);
        }
        for(vector<int>& v: mentors){
            int sum=0;
            for(int i=v.size()-1;i>=0;i--){
                sum=sum*2+(v[i]);
            }
            m.push_back(sum);
        }
        vector<bool> used(s.size(),false);
        helper(s,0,0,m,used);
        return maxm;
    }
};