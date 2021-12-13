class TrieNode{
    public:
    char ch;
    vector<TrieNode*> children;
    int traversed;
    bool terminal;
    TrieNode(char ch){
        this->ch=ch;
        children=vector<TrieNode*> (256,NULL);
        traversed=1;
        terminal=false;
    }
};
class Solution {
public:
    void insert(TrieNode* root,string& s){
        TrieNode* temp=root;
        for(char& ch: s){
            if(temp->children[ch]) {
                temp=temp->children[ch];
                (temp->traversed)++;
            }
            else{
                TrieNode* nn=new TrieNode(ch);
                temp->children[ch]=nn;
                temp=temp->children[ch];
            }
        }
        temp->terminal=true;
    }
    bool poss(TrieNode* root,string& s){
        TrieNode* temp=root;
        int cnt=0;
        for(char ch: s){
            if(temp->children[ch]==NULL or !(temp->children[ch]->terminal))
                return false;
            temp=temp->children[ch];
            cnt++;
        }
        return cnt==s.size();
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string& s1,string& s2){
            return s1.size()!=s2.size()? s1.size()>s2.size(): s1<s2;
        });
        TrieNode* root=new TrieNode('\0');
        for(string& s: words)
            insert(root,s);
        
        for(string& s: words){
            if(poss(root,s)) return s;
        }
        return "";
    }
};