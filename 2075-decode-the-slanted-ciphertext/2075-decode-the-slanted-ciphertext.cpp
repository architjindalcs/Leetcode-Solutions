class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int siz=s.size();
        int cols=(siz/rows);
        string ans="";
        for(int col=0;col<cols;col++){
            int x=0,y=col;
            while(x<rows and y<cols){
                int idx=x*cols+y;
                ans.push_back(s[idx]);
                x++;
                y++;
            }
        }
        int i=0;
        int len=ans.size();
        i=ans.size()-1;
        while(i>=0 and ans[i]==' '){
            i--;
            len--;
        }
        return ans.substr(0,len);
     
    }
};