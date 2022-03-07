class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        int ans=0;
        unordered_set<string> vis;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        while(q.size()){
            int siz=q.size();
            while(siz--){
                string fr=q.front();
                q.pop();
                if(fr==endWord) return ans+1;
                
                for(int i=0;i<fr.size();i++){
                    char ch=fr[i];
                    for(char c='a';c<='z';c++){
                        if(c==ch) continue;
                        fr[i]=c;
                        if(st.count(fr) and !vis.count(fr)){
                            q.push(fr);
                            vis.insert(fr);
                        }
                        fr[i]=ch;
                    }
                }

            }
                            ans++;
        }
        return 0;
    }
};