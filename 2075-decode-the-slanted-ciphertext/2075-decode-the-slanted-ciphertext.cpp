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
        s=ans;
        int len=s.size();

//        s=s.substr(i);
        i=s.size()-1;
        while(i>=0 and s[i]==' '){
            i--;
            len--;
        }
        return s.substr(0,len);
     
    }
};