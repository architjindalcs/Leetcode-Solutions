class Solution {
public:
    vector<vector<string>> ans;
     unordered_map<string,vector<string>> adj;
    void dfs(string src,string des,vector<string>& path){
        path.push_back(src);
        if(src==des) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(string& nei: adj[src]){
            dfs(nei,des,path);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
       // vector<vector<string>> ans;
       
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_set<string> vis;
      
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        unordered_map<string,int> dist;
        dist[beginWord]=0;
        while(q.size()){
            string fr=q.front();
            string oldfr=fr;
        
            q.pop();
            for(int i=0;i<fr.size();i++){
                char old=fr[i];
                for(char ch='a';ch<='z';ch++){
                    fr[i]=ch;
                    if(vis.count(fr) or !st.count(fr)) continue;
                    if(!dist.count(fr)){
                        dist[fr]=1+dist[oldfr];
                        adj[oldfr].push_back(fr);
                        q.push(fr);
                    }
                    else if(dist[fr]==1+dist[oldfr]){
                        adj[oldfr].push_back(fr);
                    }
                }
                fr[i]=old;
            }
        }
 
        vector<string> path;
        dfs(beginWord,endWord,path);
        return ans;
    }
};