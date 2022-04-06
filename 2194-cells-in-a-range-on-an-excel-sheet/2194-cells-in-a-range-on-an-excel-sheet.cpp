class Solution {
public:
    vector<string> cellsInRange(string s) {
        int r1=stoi(s.substr(1,1));
        int r2=stoi(s.substr(4,1));
        int c1=s[0]-'A', c2=s[3]-'A';
        int c=c2-c1;
        int r=r2-r1;
        
        vector<string> ans;
        for(char col=s[0];col<=s[3];col++){
            for(int row=r1;row<=r2;row++){
                ans.push_back(string(1,col)+to_string(row));
            }
        }
        
        return ans;
    }
};