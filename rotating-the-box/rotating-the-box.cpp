class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(vector<char>& v: box){
            int ei=v.size();
            for(int i=v.size()-1;i>=0;i--){
                if(v[i]=='*'){
                    //obst
                    ei=i;
                }
                else if(v[i]=='.'){
                    //empty space..
                    //chalte jao..
                }
                else{
                    //a leaf is there..
                    int st=i;
                    st++;
                    while(st<v.size() and st<ei){
                        st++;
                    }
                    v[i]='.';
                    v[st-1]='#';
                    ei=st-1;
                }
            }
        }
        /*
            1 2    1 3 4 
            3 4    2 4 6
            5 6
        */
       // return box;
        int r=box.size(),c=box[0].size();
        vector<vector<char>> ans(c,vector<char>(r,0));
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++)
                ans[i][j]=box[j][i];
        }
        int c1=0,c2=ans[0].size()-1;
        while(c1<c2){
            for(int i=0;i<ans.size();i++) swap(ans[i][c1],ans[i][c2]);
            c1++;
            c2--;
        }
        return ans;
    }
};