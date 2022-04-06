class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i=0;
        vector<vector<int>> ans;
        while(i<s.size()){
            int j=i,cnt=0;;
            char ch=s[i];
            while(j<s.size() and s[j]==ch){
                cnt++;
                j++;
            }
            if(cnt>=3){
                ans.push_back({i,j-1});
                i=j-1;
            }
            i++;
        }
        return ans;
    }
};