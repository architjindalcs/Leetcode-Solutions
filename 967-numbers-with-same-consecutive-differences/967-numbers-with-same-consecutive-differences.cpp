class Solution {
public:
    vector<int> ans;
    void helper(int st,int siz,int diff){
        queue<int> q;
        q.push(st);
        int level=1;
        while(q.size()){
            int size=q.size();
            while(size--){
                int fr=q.front();
                q.pop();
                if(level==siz){
                    ans.push_back(fr);
                }
                else if(level<siz){
                    if((fr%10)+diff<=9){
                        q.push(fr*10+(fr%10)+diff);
                    }
                    if(diff and (fr%10)-diff>=0){
                        q.push(fr*10+(fr%10)-diff);
                    }
                }
            }
            level++;
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int st=1;st<=9;st++) helper(st,n,k);
        return ans;
    }
};