class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int c=strs[0].size();
        bool del[c];
        memset(del,false,sizeof(del));
        for(int i=1;i<strs.size();i++){
            int dc=-1;
            for(int j=0;j<c;j++){
                if(del[j]) continue;
                if(strs[i][j]>strs[i-1][j])
                    break;
                else if(strs[i][j]<strs[i-1][j]){
                    dc=j;
                    del[dc]=true;
                    i=0;
                    ans++;
                    break;
                }
            }
        //    cout<<"dc: "<<dc<<endl;
        }
        return ans;
    }
};