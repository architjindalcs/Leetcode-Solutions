class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string,int> mapping;
        int id=0;
        for(vector<string>& v: favoriteCompanies){
            for(string& s: v) {
                if(!mapping.count(s)) mapping[s]=id++;
            }
        }
        int n=favoriteCompanies.size();
        vector<bitset<50000>> v;
        //total at max 5000 companies can be there with id 0.....4999
        for(vector<string>& vv: favoriteCompanies){
            bitset<50000> b;
            for(string& s: vv){
                b[mapping[s]]=1;
            }
            v.push_back(b);
        }
        
        vector<int> res;
        for(int i=0;i<favoriteCompanies.size();i++){
            bool isSubset=false;
            for(int j=0;j<favoriteCompanies.size();j++){
                if(i==j) continue;
                if((v[i]&v[j]) == v[i]) isSubset=true;
            }
            if(!isSubset) res.push_back(i);
        }
        return res;
    }
    
};