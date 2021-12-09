class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        //cname, tno, fooditem..
        unordered_map<string,unordered_map<string,int>> m; //tno, [fooditem,cnt];
        set<string> fitems;
        for(vector<string>& s: orders){
            string tno=s[1], foodItem=s[2];
            m[tno][foodItem]++;
            fitems.insert(foodItem);
        }
        vector<vector<string>> ans={};
        vector<string> header;
        header.push_back("Table");
        for(auto s: fitems) header.push_back(s);
        // ans.push_back(header);
        
        for(auto x: m){
            unordered_map<string,int> fcnt=x.second;
            vector<string> info;
            info.push_back(x.first);
            for(int j=1;j<header.size();j++){
                info.push_back(to_string(fcnt[header[j]]));
            }
            ans.push_back(info);
        }
        sort(ans.begin(),ans.end(),[&](vector<string>& s1,vector<string>& s2){
            return stoi(s1[0])<stoi(s2[0]);    
        });
        ans.insert(ans.begin(),header);
        return ans;
        
    }
};