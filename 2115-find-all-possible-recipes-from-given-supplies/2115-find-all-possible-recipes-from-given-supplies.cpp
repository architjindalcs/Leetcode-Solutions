class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indeg;
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                //ingredients[i][j]]++;
                indeg[recipes[i]]++;
            }
        }
        vector<string> ans;
        queue<string> q;
        for(string& supp: supplies){
            q.push(supp);
        }
        while(q.size()){
            string fr=q.front();
            q.pop();
            for(string& s: adj[fr]){
                if(--indeg[s]==0){
                    //this recipe is formed man
                    q.push(s);
                }
            }
        }
       // vector<string> ans;
        for(string& s: recipes) {
            if(indeg[s]==0) ans.push_back(s);
        }
        return ans;
    }
};