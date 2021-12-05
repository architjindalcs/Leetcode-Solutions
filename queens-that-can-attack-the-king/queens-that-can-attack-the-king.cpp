class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<string> st;
        for(vector<int>& v: queens){
            st.insert(to_string(v[0])+"#"+to_string(v[1]));
        }
        int i=king[0],j=king[1];
        vector<vector<int>> ans;
        while(i<8){
            string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            i++;
        }
        i=king[0],j=king[1];
        while(i>=0){
            string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            i--;
        }
        i=king[0],j=king[1];
        while(j>=0){
             string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            j--;
        }
        i=king[0],j=king[1];
        while(j<8){
             string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            j++;
        }
        i=king[0],j=king[1];
        while(i>=0 and j>=0){
               string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            i--;
            j--;
        }
        i=king[0],j=king[1];
        while(i>=0 and j<8){
               string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            i--;
            j++;
        }
        i=king[0],j=king[1];
        while(i<8 and j>=0){
               string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            i++;
            j--;
        }
        
        i=king[0],j=king[1];
        while(i<8 and j<8){
               string temp=to_string(i)+"#"+to_string(j);
            if(st.count(temp)){
                ans.push_back({i,j});
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
};